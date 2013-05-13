#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "assert.h"
#include <typeinfo>
#include <stdio.h>
#include <iostream>
//a for loop from begin to end
#define forall(iterator,listptr) \
  for(typeof((listptr)->begin())iterator = (listptr)->begin(); \
      iterator != (listptr)->end(); ++iterator)

// the default attribute propagation rule
// sets the node's scope to the current scope 
// and then visits the children of the node
#define set_scope_and_descend_into_children(X) \
        (X)->m_attribute.m_scope = m_st->get_scope(); \
        (X)->visit_children(this); \

#define print_out(X) \
        fprintf(m_outputfile, X);

class Codegen : public Visitor
{
	private:

	FILE * m_outputfile;
	SymTab *m_st;
	int thecount;
	// basic size of a word (integers and booleans) in bytes
	static const int wordsize = 4;

	int label_count; //access with new_label

	// ********** Helper functions ********************************

	// this is used to get new unique labels (cleverly named label1, label2, ...)
	int new_label() { return label_count++; }

	// this mode is used for the code
	void set_text_mode() { fprintf( m_outputfile, ".text\n\n"); }
	
	// PART 1:
	// 1) get arithmetic expressions on integers working:
	//	  you wont really be able to run your code,
	//	  but you can visually inspect it to see that the correct
	//    chains of opcodes are being generated.
	// 2) get function calls working:
	//    if you want to see at least a very simple program compile
	//    and link successfully against gcc-produced code, you
	//    need to get at least this far
	// 3) get boolean operation working
	//    before we can implement any of the conditional control flow 
	//    stuff, we need to have booleans worked out.  
	// 4) control flow:
	//    we need a way to have if-elses and while loops in our language. 
	//
	// Hint: Symbols have an associated member variable called m_offset
	//    That offset can be used to figure out where in the activation 
	//    record you should look for a particuar variable

	///////////////////////////////////////////////////////////////////////////////
	//
	//  function_prologue
	//  function_epilogue
	//
	//  Together these two functions implement the callee-side of the calling
	//  convention.  A stack frame has the following layout:
	//
	//                          <- SP (before pre-call / after post-ret)
	//  high -----------------
	//       | actual arg n  |
	//       | ...           |
	//       | actual arg 1  |  <- SP (just before call / just after ret)
	//       -----------------
	//       |  Return Addr  |  <- SP (just after call / just before ret)
	//       =================
	//       | previous %ebp |
	//       -----------------
	//       | temporary 1   |
	//       | ...           |
	//       | temporary n   |  <- SP (after prologue / before epilogue)
	//  low  -----------------
	//
	//
	//			  ||		
	//			  ||
	//			 \  /
	//			  \/
	//
	//
	//  The caller is responsible for placing the actual arguments
	//  and the return address on the stack. Actually, the return address
	//  is put automatically on the stack as part of the x86 call instruction.
	//
	//  On function entry, the callee
	//
	//  (1) allocates space for the callee's temporaries on the stack
	//  
	//  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%ebp)
	//
	//  (3) makes the activation record pointer (frame pointer - %ebp) point to the start of the temporary region
	//
	//  (4) possibly copies the actual arguments into the temporary variables to allow easier access
	//
	//  On function exit, the callee:
	//
	//  (1) pops the callee's activation record (temporary area) off the stack
	//  
	//  (2) restores the callee-saved registers, including the activation record of the caller (%ebp)	 
	//
	//  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the 
	//	  return address off the stack. After the ret, remove the arguments from the stack
	//
	//	For more info on this convention, see http://unixwiz.net/techtips/win32-callconv-asm.html
	//
	//	This convention is called __cdecl
	//
	//////////////////////////////////////////////////////////////////////////////
  

  void emit_prologue(SymName *name, unsigned int size_locals, unsigned int count)
  {
    //save the state of your stack and allocate memory for variables
    fprintf(m_outputfile, "%s:\n", name->spelling());
    print_out( "\tpushl\t%%ebp\n");
    print_out( "\tmovl\t%%esp,%%ebp\n");
    fprintf(m_outputfile, "\tsubl\t$%d,%%esp\n", size_locals);
  }

  void emit_epilogue()
  {

    // opposite of save the state of your stack and allocate memory for variables
    print_out( "\tmovl\t%%ebp,%%esp\n");
    print_out( "\tpopl\t%%ebp\n");
    print_out( "\tret\n");
  }
  
  // HERE: more functions to emit code

///////////////////////////////////////////////
/////////////////////////////////

public:
  
  Codegen(FILE * outputfile, SymTab * st)
  {
	m_outputfile = outputfile;
	m_st = st;
	
	label_count = 0;

  }
  
  void visitProgramImpl(ProgramImpl * p)
  {
	thecount = 0;
    set_text_mode();
    print_out( "\t.globl\tMain\n");
    p->visit_children(this);
  }
  void visitFuncImpl(FuncImpl *p) 
  {
	emit_prologue(p->m_symname, m_st->scopesize(((ReturnImpl*)(((FuncBlockImpl*)(p->m_funcblock))->m_return))->m_attribute.m_scope), p->m_decl_list->size());
    p->visit_children(this);
    emit_epilogue();
  }
  void visitFuncBlockImpl(FuncBlockImpl *p) 
  {
    p->visit_children(this);
  }
  void visitStatBlockImpl(StatBlockImpl *p) 
  {
    p->visit_children(this);

  }
  void visitAssignment(Assignment * p)
  {
    p->visit_children(this);

    print_out( "\tpopl\t%%eax\n");
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
	if (s->get_offset() >= 0){
    fprintf(m_outputfile,  "\tmovl\t%%eax, %d(%%ebp)\n", s->get_offset()+8 ); 
	} else {
    fprintf(m_outputfile,  "\tmovl\t%%eax, %d(%%ebp)\n", s->get_offset() ); 
	}

  }
  void visitArrayAssignment(ArrayAssignment * p)
  {

    p->visit_children(this);
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ebx\n");
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
    print_out( "\timull\t$4, %%ebx\n");
	if (s->get_offset() >= 0){
    fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", (s->get_offset()+8));
	} else {
    fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", s->get_offset());
	}
    fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", 4);
    print_out( "\tneg\t%%ebx\n");
    print_out( "\taddl\t%%ebp, %%ebx\n");
    print_out( "\tmovl\t%%eax, (%%ebx)\n");
  }
  void visitCall(Call * p)
  {
    int count = 0;
    list<Expr_ptr>::reverse_iterator expr_iter;
    forall(expr_iter,p->m_expr_list)
    {
      count++;
      (*expr_iter)->accept( this );
    }
    fprintf(m_outputfile, "\tcall\t%s\n", p->m_symname_2->spelling());
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname_1->spelling());
	if (s->get_offset() >= 0){
    fprintf(m_outputfile, "\tmovl\t%%eax, %d(%%ebp)\n", (s->get_offset()+8)); 
	} else {
    fprintf(m_outputfile, "\tmovl\t%%eax, %d(%%ebp)\n", s->get_offset()); 
	}
	list<Expr_ptr>::reverse_iterator other_iter;
    forall(other_iter,p->m_expr_list)
    {
      fprintf(m_outputfile, "\tpopl %%eax\n");
    }
 
  }
  void visitArrayCall(ArrayCall *p)
  {

    int num_arguments = 0;
    list<Expr_ptr>::reverse_iterator m_expr_list_iter;
    for(m_expr_list_iter = p->m_expr_list_2->rbegin();
    m_expr_list_iter != p->m_expr_list_2->rend();
    ++m_expr_list_iter)
    {
      num_arguments++;
      (*m_expr_list_iter)->accept( this );
    }
    fprintf(m_outputfile, "\tcall\t%s\n", p->m_symname_2->spelling());
    p->m_expr_1->accept(this);
    print_out( "\tpopl\t%%ebx\n");
    print_out( "\timull\t$4, %%ebx\n");
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname_1->spelling());
	if (s->get_offset() >= 0){
    fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", (s->get_offset()+8));
	} else {
	fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", s->get_offset());
	}
    fprintf(m_outputfile, "\taddl\t$%d, %%ebx\n", 4);
    print_out( "\tneg\t%%ebx\n");
    print_out( "\taddl\t%%ebp, %%ebx\n");
    print_out("\tmovl\t%%eax, (%%ebx)\n");

  }
  void visitReturnImpl(ReturnImpl * p)
  { 
   p->visit_children(this);
   print_out( "\tpopl\t%%eax\n");
  }
  void visitYield(Yield * p)
  {
  }

  // control flow
  void visitIfNoElse(IfNoElse* p) {
    int label = new_label();
    // evaluate expression
    // pop the result off the stack into, say, %eax

    
	//p->visit_children(this);
	p->m_expr->accept(this);
	print_out( "\tmovl $0, %%ebx\n");
    print_out( "\tcmp %%eax, %%ebx\n");
    fprintf(m_outputfile, "\tje jump_if_%d\n", label);
	p->m_statblock->accept(this);
    // visit the statements inside the if block
    fprintf(m_outputfile, "jump_if_%d:\n", label);

  }
  void visitIfWithElse(IfWithElse * p)
  {

    int else_label = new_label();
    int done_label = new_label();
    p->m_expr->accept(this);
	p->m_statblock_1->accept(this);
    print_out( "\tpopl\t%%ecx\n");
    fprintf(m_outputfile, "\tjecxz\telse_label_%d\n", else_label);
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "else_label_%d:\n", else_label);
	p->m_statblock_2->accept(this);
    fprintf(m_outputfile, "done_label_%d:\n", done_label);

  }
  void visitWhileLoop(WhileLoop * p)
  {

    int loop_label = new_label();
    int done_label = new_label();
    fprintf(m_outputfile, "loop_label_%d:\n", loop_label);
    p->m_expr->accept(this);
    fprintf(m_outputfile, "\tpopl\t%%ecx\n");
    fprintf(m_outputfile, "\tjecxz\tdone_label_%d\n", done_label);
	p->m_statblock->accept(this);
    fprintf(m_outputfile, "\tjmp\tloop_label_%d\n", loop_label);    
    fprintf(m_outputfile, "done_label_%d:\n", done_label);

  }

  // variable declarations (no code generation needed)
  void visitDeclImpl(DeclImpl * p)
  {
        p->visit_children(this);

  }
  void visitTInteger(TInteger * p)
  {
        p->visit_children(this);

  }
  void visitTBoolean(TBoolean * p)
  {
        p->visit_children(this);

  }
  void visitTRational(TRational * p)
  {
        p->visit_children(this);
  }
  void visitTAuto(TAuto * p)
  {
        p->visit_children(this);

  }
  void visitTIntArray(TIntArray * p)
  {
        p->visit_children(this);

  }

  // comparison operations
  void visitCompare(Compare * p)
  {
     p->visit_children(this);
    int true_label = new_label();
    int done_label = new_label();

    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");

  }
  void visitNoteq(Noteq * p)
  {
    p->visit_children(this);
    int false_label = new_label();
    int done_label = new_label();

    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\tfalse_label_%d\n", false_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "jmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "false_label_%d:\n", false_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");

  }
  void visitGt(Gt * p)
  {

    p->visit_children(this);
    int true_label = new_label();
    int false_label = new_label();
    int done_label = new_label();
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\tfalse_label_%d\n", false_label);
    print_out( "\tshr\t$31, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    fprintf(m_outputfile, "false_label_%d:\n", false_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");
 /*
    p->visit_children(this);
    int true_label = new_label();
    int false_label = new_label();
    int done_label = new_label();
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjg\tfalse_label_%d\n", false_label);
    print_out( "\tshr\t$31, %%ecx\n");
    fprintf(m_outputfile, "\tjmp\ttrue_label_%d\n", true_label);
    fprintf(m_outputfile, "false_label_%d:\n", false_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");
*/
  }
  void visitGteq(Gteq * p)
  {

    p->visit_children(this);
    int true_label = new_label();
    int done_label = new_label();
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    print_out( "\tshr\t$31, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");

  }
  void visitLt(Lt * p)
  {
    p->visit_children(this);
    int true_label = new_label();
    int false_label = new_label();
    int done_label = new_label();
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjle\tfalse_label_%d\n", false_label);
    print_out( "\tshr\t$31, %%ecx\n");
    fprintf(m_outputfile, "\tjmp\ttrue_label_%d\n", true_label);
    fprintf(m_outputfile, "false_label_%d:\n", false_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");
   }
  void visitLteq(Lteq * p)
  {

    p->visit_children(this);
    int true_label = new_label();
    int done_label = new_label();
	int peng_label = new_label();
    print_out( "\tpopl\t%%ecx\n");
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tsubl\t%%eax, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    print_out( "\tshr\t$31, %%ecx\n");
    fprintf(m_outputfile, "\tjecxz\ttrue_label_%d\n", true_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile, "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile, "true_label_%d:\n", true_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile, "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");

  }

  // arithmetic and logic operations

  void print_basic_arith_start(){
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tpopl\t%%ebx\n");
  }

  void visitAnd(And * p)
  {


    p->visit_children(this);
    print_basic_arith_start();
    print_out( "\tandl\t%%ebx, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitOr(Or * p)
  {

    p->visit_children(this);
    print_basic_arith_start();
    print_out( "\torl\t%%ebx, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitMinus(Minus * p)
  {

    p->visit_children(this);
    print_out( "\tpopl\t%%ebx\n");
    print_out( "\tpopl\t%%eax\n");
    print_out( "\tsubl\t%%ebx, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitPlus(Plus * p)
  {

    p->visit_children(this);
    print_basic_arith_start();
    print_out( "\taddl\t%%ebx, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitTimes(Times * p)
  {

    p->visit_children(this);
    print_basic_arith_start();
    print_out( "\timull\t%%ebx, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitDiv(Div * p)
  {

    p->visit_children(this);
    print_out( "\tmovl\t$1, %%eax\n");
    print_out( "\tmovl\t$1, %%ebx\n");
    print_out( "\timull\t%%ebx\n");
    print_out( "\tpopl\t%%ebx\n");
    print_out("\tpopl\t%%eax\n");
    print_out( "\tidivl\t%%ebx\n");
    print_out( "\tpushl\t%%eax\n");

  }
  void visitNot(Not * p)
  {

    p->visit_children(this);
    int first_label = new_label();
    int done_label = new_label();
    print_out( "\tpopl\t%%ecx\n");
    fprintf(m_outputfile,  "\tjecxz\tFirst_%d\n", first_label);
    print_out( "\tmovl\t$0, %%eax\n");
    fprintf(m_outputfile,  "\tjmp\tdone_label_%d\n", done_label);
    fprintf(m_outputfile,  "First_%d:\n", first_label);
    print_out( "\tmovl\t$1, %%eax\n");
    fprintf(m_outputfile,  "done_label_%d:\n", done_label);
    print_out( "\tpushl\t%%eax\n");

  }
  void visitUminus(Uminus * p)
  {

    p->visit_children(this);
    print_out( "\tpopl\t%%eax\n");
    print_out( "\timull\t$-1, %%eax\n");
    print_out( "\tpushl\t%%eax\n");

  }


  void visitIdent(Ident * p)
  {

    p->visit_children(this);
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
	if (s->get_offset() >= 0){
	     fprintf(m_outputfile, "\tpushl\t%d(%%ebp)\n", (s->get_offset()+8));
	} else {
    fprintf(m_outputfile, "\tpushl\t%d(%%ebp)\n", (s->get_offset()));
	}
  }
  void visitIntLit(IntLit * p)
  {

    p->visit_children(this);
    fprintf(m_outputfile, "\tpushl\t$%d\n", p->m_primitive->m_data);

  }
  void visitRatLit(RatLit * p)
  {
  }
  void visitBoolLit(BoolLit * p)
  {

    p->visit_children(this);
    fprintf(m_outputfile,  "\tpushl\t$%d\n", p->m_primitive->m_data);

  }
  void visitArrayAccess(ArrayAccess * p)
  {

    p->visit_children(this);
    print_out( "\tpopl\t%%ebx\n");
    Symbol *s = m_st->lookup(p->m_attribute.m_scope, p->m_symname->spelling());
    print_out(  "\timull\t$4, %%ebx\n");
	if (s->get_offset() >= 0){
    fprintf(m_outputfile,  "\taddl\t$%d, %%ebx\n", (s->get_offset())+8);
	} else{
    fprintf(m_outputfile,  "\taddl\t$%d, %%ebx\n", (s->get_offset()));
	}
    fprintf(m_outputfile,  "\taddl\t$%d, %%ebx\n", 4);
    print_out(  "\tneg\t%%ebx\n");
    print_out(  "\taddl\t%%ebp, %%ebx\n");
    print_out(  "\tpushl\t(%%ebx)\n");

  }

  // special cases
  void visitSymName(SymName * p)
  {
  }
  void visitPrimitive(Primitive * p)
  {
  }
};

void dopass_codegen(Program_ptr ast, SymTab * st)
{
	Codegen *codegen = new Codegen(stdout, st);     // create the visitor
	ast->accept(codegen);                           // walk the tree with the visitor above
  	st->dump(stdout);
	delete codegen;
}
