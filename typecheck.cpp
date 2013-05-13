#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "assert.h"
#include "stdio.h"
#include <map>

//for loop for iterating over containers (such as lists)
//creates an iterator of the appropriate type and does
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


class Typecheck : public Visitor {
private:
  FILE *m_errorfile;
  SymTab *m_st;
  int maincount;
  map<string, int> decl_list;
  string theident;
  int theidenttype;
  int globreturn;
  // the set of recognized errors                                               
  enum errortype {
    no_main,
    nonvoid_main,
    ident_dup,
    ident_undef,
    ident_mismatch,
    arg_mismatch,
    return_mismatch,
    yeild_mismatch,
    assign_mismatch,
    condition_mismatch,
    expr_mismatch,
    rational_bad,
    array_index,
  };

  // print the error to file and exit                                           
  void t_error(errortype e, Attribute a) {
    switch(e) {
    case no_main:
      fprintf(m_errorfile,"error: no Main procedure\n");
      exit(1); // Line numbers don't make sense here                            
    case nonvoid_main:
      fprintf(m_errorfile,"error: the Main procedure has arguments");
      break;
    case ident_dup:
      fprintf(m_errorfile,"error: duplicate identifier in same scope");
      break;
    case ident_undef:
      fprintf(m_errorfile,"error: undefined identifier");
      break;
    case ident_mismatch:
      fprintf(m_errorfile,"error: attempt to use identifier of wrong type");
      break;
    case arg_mismatch:
      fprintf(m_errorfile,"error: arg mismatch in procedure call");
      break;
    case return_mismatch:
      fprintf(m_errorfile, "error: type mismatch in return statement");
      break;
    case yeild_mismatch:
      fprintf(m_errorfile, "error: type mismatch in yeild statement");
      break;
    case assign_mismatch:
      fprintf(m_errorfile,"error: assignment type does not match");
      break;
    case condition_mismatch:
      fprintf(m_errorfile,"error: condition statement is not boolean");
      break;
    case expr_mismatch:
      fprintf(m_errorfile,"error: incompatible types used in expression");
      break;
    case rational_bad:
      fprintf(m_errorfile,"error: badly formed rational");
      break;
    case array_index:
      fprintf(m_errorfile, "error: array index not integer");
      break;
    default: assert(0);
    }
    fprintf(m_errorfile," on line number %d\n", a.lineno);
    exit(1);
  }

  //Some helpers to lighten up the code


  Basetype getBasetype(Expr *someone){
    return someone->m_attribute.m_basetype;
  }

  const char* getSpelling(FuncImpl *p){
    return p->m_symname->spelling();
  }


  // check that there is one and only one main
  void check_for_one_main(ProgramImpl *p) {
		bool  has_main = false;
    string s = "Main";
    char *a=new char[s.size()+1];
    a[s.size()]=0;
    memcpy(a,s.c_str(),s.size());
    
    // st.open_scope();
    // Symbol* f;
    // if (!strcmp(f->spelling(),"Main"))
    // {
    //   cout << "hello" << endl;
    // }


    list<Func_ptr>::iterator m_func_list_iter;
		forall(m_func_list_iter, p->m_func_list)
	  {
      if (compare_string(m_func_list_iter,a))
      {
  			if ( has_main == false )
  	  	{
  		  		has_main = true;
  			}
  			else
  			{ 
  	        	this->t_error(ident_dup, (*m_func_list_iter)->m_attribute);
  			}
		  }
	  }
		if (has_main==false)
		{
			this->t_error(no_main, p->m_attribute);
		}
  }

  bool compare_string(list<Func_ptr>::iterator iter, char *look){
    bool contains = false;
    //cout << "look is: " << look << endl;
    //cout << "inter is: " << ((FuncImpl *)(*iter))->m_symname->spelling() << endl;
    //cout << "result is: " << strncmp(((FuncImpl *)(*iter))->m_symname->spelling(), look, strlen(look)) << endl;
    if (strncmp(((FuncImpl *)(*iter))->m_symname->spelling(), look, strlen(look)) == 0)
    {
      contains = true;
    } else {
      contains = false;
    }
    //cout << contains << endl;
    return contains;
  }
  // create a symbol for the procedure and check there is none already existing
  void add_proc_symbol(FuncImpl *p) {

    // map<string,int>::const_iterator it = decl_list.find("z");
   

    Symbol *s = new Symbol();
    s->m_basetype = bt_procedure;
    s->m_return_type = p->m_type->m_attribute.m_basetype;
    vector<Basetype> args;
    list<Decl_ptr>::iterator decl_iter;
    // cout << "got here " << endl;
    char *name = strdup(getSpelling(p));
    // cout << "in add proc symbol spelling is " << strdup(getSpelling(p)) << endl;
    forall(decl_iter, p->m_decl_list)
    {
      // cout << "and here " << endl;
      // cout << "in add proc symbol spelling is " << strdup(getSpelling(p)) << endl;
      Basetype types = (*decl_iter)->m_attribute.m_basetype;
      int type_size = ((DeclImpl *)(*decl_iter))->m_symname_list->size();
      for (int i=0; i<type_size; i++)
      args.push_back(types);
    }
    // cout << "now here" << endl;



    s->m_arg_type = args;
    if ( !m_st->insert_in_parent_scope(name, s) )
    {
      this->t_error(nonvoid_main, p->m_attribute);
    }
  }

  // add symbol table information for all the declarations following
  void add_decl_symbol(DeclImpl *p) {
    // cout << "in add decl symbol" << endl;
    char *name;
    Symbol *s;
    list<SymName_ptr>::iterator iter;
    forall (iter,p->m_symname_list)
    {
      name = strdup((*iter)->spelling());
      Basetype temptype = p->m_attribute.m_basetype;
      //cout << "name is: " << name << " and is of type: " << temptype << endl;
      decl_list.insert(pair<string, int>(name, temptype));
      s = new Symbol();
      s->m_basetype = p->m_attribute.m_basetype;
      if ( !m_st->insert(name, s) )
      {
        this->t_error(ident_dup, p->m_attribute);
      }
    }
  }
  

  // check that the return statement of a procedure has the appropriate type.
  //check that the declared return type is not an array 
  void check_proc(FuncImpl *p) {

  /*
    case bt_integer:  return 4;
    case bt_rational: return 8;
    case bt_boolean:  return 4;
    case bt_intarray: return 0; 
    case bt_procedure:  return 0;
  */
  //cout << "line says: " << getSpelling(p) << endl;
  // if (decl_list.count("2") != 0){
  //     cout << "exists" << endl;
  // }


    vector<string> v;
    for(map<string,int>::iterator it = decl_list.begin(); it != decl_list.end(); ++it) {
      v.push_back(it->first);
      // cout << it->first << "\t" <<  it->second << endl;
    }
    // cout << "spelling here is: " << endl;
    
    // SymName *sn = (((FuncBlockImpl *)(p->m_funcblock))->m_return)->m_attribute.m_symname;

  string s = "Main";
  char *a=new char[s.size()+1];
  a[s.size()]=0;
  memcpy(a,s.c_str(),s.size());
  Basetype decl_t = p->m_type->m_attribute.m_basetype;
  // cout << " decl_t is : " << p->m_type->m_attribute.m_basetype << endl;
  Basetype ret_t =  (((FuncBlockImpl *)(p->m_funcblock))->m_return)->m_attribute.m_basetype;
  Basetype parent_t = p->m_parent_attribute->m_basetype;
  // cout << "ret_t is: " << ret_t << " and: m_parent " << parent_t << endl;
  //cout << "theidentype here is " << theidenttype << endl;

  if ( parent_t != bt_procedure && strncmp(getSpelling(p), a, strlen(a)) == 0)
    {
      maincount++;
      //cout << "maincount is now: " << maincount << endl;
      if (maincount > 1){
        this->t_error(ident_dup, p->m_attribute); //Nested mains (or double.. kind of a hack)
      }
    }
  if (decl_t != theidenttype && decl_t != globreturn)
    {
      //cout << "test here" << endl;
      this->t_error(return_mismatch, ((Return *)((FuncBlockImpl *)(p->m_funcblock))->m_return)->m_attribute);
    }
  if (decl_t == bt_intarray)
    {
          this->t_error(return_mismatch, p->m_type->m_attribute);
    }
  }

  // create a symbol for the procedure and check there is none already existing
  void check_call(Call *p) {
    list<Expr_ptr> *expr_list = p->m_expr_list;
    SymName *sn = p->m_symname_2;
    Symbol *s = m_st->lookup(sn->spelling());
    Basetype s_basetype = s->m_basetype;
    if ( s_basetype!= bt_procedure || !s)
    {
        this->t_error(condition_mismatch,  p->m_attribute);
    }
    if (s->m_arg_type.size() != (*expr_list).size())
    {
      this->t_error(assign_mismatch,  p->m_attribute);
    }
    int count = 0;
    list<Expr_ptr>::iterator expr_iter;
    forall(expr_iter,expr_list)
    {
      if ((s->m_arg_type)[count] != getBasetype(*expr_iter))
      this->t_error(arg_mismatch,  p->m_attribute);
      count++;
    }
  }

  Symbol getSymbol(SymName *sn){

  }
  void check_array_call(ArrayCall *p) {
    Symbol *proc_s = m_st->lookup(p->m_symname_2->spelling());
    Symbol *var_s = m_st->lookup(p->m_symname_1->spelling());
    
    if ( proc_s->m_return_type != bt_integer )
    {
      this->t_error(array_index, p->m_attribute);
    }
    if (!var_s)
    {
      this->t_error(ident_undef, p->m_attribute);
    }
    if( var_s->m_basetype != bt_intarray )
    {
      this->t_error(array_index, p->m_attribute);
    }
    if (!proc_s)
    {
      this->t_error(expr_mismatch, p->m_attribute);
    }
    if (p->m_expr_1->m_attribute.m_basetype != bt_integer)
    {
      this->t_error(array_index, p->m_expr_1->m_attribute);
    }
  }

  //for checking that this expressions type is boolean  
  //used in if/else and while visits
  void check_pred(Expr *pred) {
     if (getBasetype(pred) != bt_boolean)
     {
        this->t_error(condition_mismatch,  pred->m_attribute);
     }
  }

  void check_assignment(Assignment *p) {
    Symbol *s = m_st->lookup(p->m_symname->spelling());
    if (!s)
    {
      this->t_error(ident_undef, p->m_attribute);
    }
    if( s->m_basetype != getBasetype(p->m_expr))
    {
      this->t_error(assign_mismatch, p->m_attribute);
    }
  }

  //for checking boolean operations (and, or ...)
  void checkset_boolexpr(Expr *parent, Expr *child1, Expr *child2) {
    if ( getBasetype(parent) != bt_boolean || getBasetype(child1) != bt_boolean || getBasetype(child2) != bt_boolean )
    {
     // cout << "error in the boolean operations" << endl;
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

  //for checking arithmetic expressions (plus, times, ...)
  void checkset_arithexpr(Expr *parent, Expr *child1, Expr *child2) {
  if ( getBasetype(parent) != bt_integer || getBasetype(child1) != bt_integer || getBasetype(child2) != bt_integer )
    {
      // cout << "error in the arthemitec expression" << endl;
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

  //for checking relational (less than , greater than, ...)
  void checkset_relationalexpr(Expr *parent, Expr *child1, Expr *child2) {
    Basetype p_type = getBasetype(parent);
    Basetype c1 = getBasetype(child1);
    Basetype c2 = getBasetype(child2);
    if ( !(p_type == bt_boolean && ( (c1 == bt_integer && c2 == bt_integer) || (c1 == bt_boolean && c2 == bt_boolean) ) ) )
    {
      // cout << "error in checkset relationship exper" << endl;
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

  //for checking equality ops (equal, not equal)
  void checkset_equalityexpr(Expr *parent, Expr *child1, Expr *child2) {
    Basetype p_type = getBasetype(parent);
    Basetype c1 = getBasetype(child1);
    Basetype c2 = getBasetype(child2);
    if ( !( (c1 == bt_integer && c2 == bt_integer) || (c1 == bt_boolean && c2 == bt_boolean) ) )
    {
      this->t_error(expr_mismatch, parent->m_attribute);
    }
    if ( p_type != bt_boolean )
    {
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

  //for checking not
  void checkset_not(Expr *parent, Expr *child) {
    //cout << "test for checkset_not" << endl;
    Basetype p_type = getBasetype(parent);
    Basetype c1 = getBasetype(child);
    if ( !(p_type == bt_boolean && ( (c1 == bt_boolean) ) ) )
    {
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

  //for checking unary integer (uplus, uminus)
  void checkset_unary_integer(Expr *parent, Expr *child) {
    //cout << "test for checkset_unary_integer" << endl;
    Basetype p_type = getBasetype(parent);
    Basetype c1 = getBasetype(child);
    if ( !(p_type == bt_integer && ( (c1 == bt_integer) ) ) )
    {
      this->t_error(expr_mismatch, parent->m_attribute);
    }
  }

public:
  Typecheck(FILE *errorfile, SymTab *st) {
    m_errorfile = errorfile;
    m_st = st;
  }

  void visitProgramImpl(ProgramImpl *p) {
    set_scope_and_descend_into_children(p);
    p->m_attribute.m_basetype = bt_procedure;
    check_for_one_main(p);
    // m_st->dump(cerr);
  }

  void visitFuncImpl(FuncImpl *p) {
    m_st->open_scope();
	m_st ->set_param_mode();
	p->m_attribute.m_scope = m_st->get_scope();
	p->m_type->accept(this);
    p->m_attribute.m_basetype = bt_procedure;

    //visitSymName(p->m_symname); 
    list<Decl_ptr>::iterator decl_iter;
    forall(decl_iter,p->m_decl_list)
    {
      (*decl_iter)->accept(this); 
    }
    add_proc_symbol(p);
    p->m_funcblock->accept(this);
    check_proc(p);
    m_st->close_scope(); 
 }
  void visitFuncBlockImpl(FuncBlockImpl *p) {
	m_st->set_local_mode();
    set_scope_and_descend_into_children(p);
  }
  void visitStatBlockImpl(StatBlockImpl *p) {
    set_scope_and_descend_into_children(p);
  }

  void visitDeclImpl(DeclImpl *p) {
    set_scope_and_descend_into_children(p);
    add_decl_symbol(p);
  }
  void visitAssignment(Assignment *p) {
    set_scope_and_descend_into_children(p);
    check_assignment(p);
  }
  void visitArrayAssignment(ArrayAssignment *p) {
    p->m_attribute.m_basetype = bt_intarray;
    set_scope_and_descend_into_children(p);
  }
  void visitCall(Call *p) {
    set_scope_and_descend_into_children(p);
    check_call(p);
  }
  void visitArrayCall(ArrayCall *p) {
    set_scope_and_descend_into_children(p);  
    check_array_call(p);
  }
  void visitReturnImpl(ReturnImpl *p) {
    set_scope_and_descend_into_children(p);
    //cout << "visitReturn basetype here is: " << p->m_expr->m_attribute.m_basetype << endl;
    globreturn = p->m_expr->m_attribute.m_basetype;
    if (p->m_expr->m_attribute.m_basetype == bt_intarray)
    {
      t_error(return_mismatch, p->m_attribute);
    }
    p->m_parent_attribute->m_basetype = p->m_expr->m_attribute.m_basetype;
  }
  void visitYield(Yield *p) {
    set_scope_and_descend_into_children(p);
    Basetype yieldbase = p->m_expr->m_attribute.m_basetype;
    if (yieldbase == bt_intarray)
    {
      t_error(yeild_mismatch, p->m_attribute);
    }
  }
  void visitIfNoElse(IfNoElse *p) {
    p->visit_children(this);
    check_pred(p->m_expr);
    p->m_attribute.m_scope = m_st->get_scope();
  }
  void visitIfWithElse(IfWithElse *p) {
    set_scope_and_descend_into_children(p);
    if (p->m_expr->m_attribute.m_basetype != bt_boolean)
    {
      this->t_error(condition_mismatch, p->m_expr->m_attribute);
    }
  }
  void visitWhileLoop(WhileLoop *p) {
    p->visit_children(this);
    check_pred(p->m_expr);
    p->m_attribute.m_scope = m_st->get_scope();
  }
  void visitTInteger(TInteger *p) {
    p->m_attribute.m_basetype = bt_integer;
    set_scope_and_descend_into_children(p);
    p->m_parent_attribute->m_basetype = bt_integer;
  }
  void visitTBoolean(TBoolean *p) {
    p->m_attribute.m_basetype = bt_boolean;
    set_scope_and_descend_into_children(p);
    p->m_parent_attribute->m_basetype = bt_boolean;
  }
  void visitTRational(TRational *p) {
    p->m_attribute.m_basetype = bt_rational;
    set_scope_and_descend_into_children(p);
    p->m_parent_attribute->m_basetype = bt_rational;
  }
  void visitTAuto(TAuto *p) {
    p->m_attribute.m_basetype = bt_auto;
    set_scope_and_descend_into_children(p);
    p->m_parent_attribute->m_basetype = bt_auto;
  }
  void visitTIntArray(TIntArray *p) {
    p->m_attribute.m_basetype = bt_intarray;
    set_scope_and_descend_into_children(p);
    p->m_parent_attribute->m_basetype = bt_intarray;
  }
  void visitAnd(And *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_boolexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitDiv(Div *p) {
  p->m_attribute.m_basetype = bt_integer;
  set_scope_and_descend_into_children(p);
  checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitCompare(Compare *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitGt(Gt *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitGteq(Gteq *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitLt(Lt *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitLteq(Lteq *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_relationalexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitMinus(Minus *p) {
  p->m_attribute.m_basetype = bt_integer;
  set_scope_and_descend_into_children(p);
  checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitNoteq(Noteq *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_equalityexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitOr(Or *p) {
  p->m_attribute.m_basetype = bt_boolean;
  set_scope_and_descend_into_children(p);
  checkset_boolexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitPlus(Plus *p) {
  p->m_attribute.m_basetype = bt_integer;
  set_scope_and_descend_into_children(p);
  checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
  }
  void visitTimes(Times *p) {
  p->m_attribute.m_basetype = bt_integer;
  set_scope_and_descend_into_children(p);
  checkset_arithexpr(p, p->m_expr_1, p->m_expr_2);
  }

  void visitNot(Not *p) {
    p->m_attribute.m_basetype = bt_boolean;
    set_scope_and_descend_into_children(p);
    if (p->m_expr->m_attribute.m_basetype != bt_boolean)
    {
      this->t_error(condition_mismatch, p->m_attribute);
    }
  }
  void visitUminus(Uminus *p) {
    	set_scope_and_descend_into_children(p);
	//p->visit_children(this);
	p->m_attribute.m_basetype = bt_integer;
	p->m_parent_attribute->m_basetype = bt_integer;
	checkset_unary_integer(p, p->m_expr);
	//p->m_attribute.m_scope = m_st->get_scope();
 }

  void visitIdent(Ident *p) {
    // cout << "here in visitIdent" << endl;
    set_scope_and_descend_into_children(p);
    Symbol *s;
    s = m_st->lookup(p->m_symname->spelling());
    if (!s)
    {
      this->t_error(ident_undef, p->m_attribute);
    }
    Basetype identbase = s->m_basetype;
    p->m_attribute.m_basetype = s->m_basetype;
    theident = p->m_symname->spelling();
    // cout << "name of ident is " << theident;
    theidenttype = s->m_basetype;
    // cout << "ident is: " << theident << " and basetype is: " << theidenttype << endl;
  }
  void visitArrayAccess(ArrayAccess *p) {
    set_scope_and_descend_into_children(p);
    p->m_attribute.m_basetype = bt_integer;
    Symbol *s = m_st->lookup(p->m_symname->spelling());
    if (!s) 
    {
      this->t_error(ident_undef,  p->m_attribute);
    }
    if (s->m_basetype != bt_intarray)
    {
      this->t_error(assign_mismatch,  p->m_attribute); 
    }
    if (p->m_expr->m_attribute.m_basetype != bt_integer)
    {
      this->t_error(array_index,  p->m_expr->m_attribute);
    }
  }
  void visitIntLit(IntLit *p) {
    //cout << "doing IntLit shit" << endl;
    set_scope_and_descend_into_children(p);
    p->m_attribute.m_basetype = bt_integer;
  }
  void visitRatLit(RatLit *p) {
    set_scope_and_descend_into_children(p);
    p->m_attribute.m_basetype = bt_rational;
  }
  void visitBoolLit(BoolLit *p) {
    //cout << "doing Bool Lit shit" << endl;
    // cout << "fucking boolean literal" << endl;
    set_scope_and_descend_into_children(p);
    p->m_attribute.m_basetype = bt_boolean;
  }

  //special cases
  void visitSymName(SymName *p) {}
  void visitPrimitive(Primitive *p) {}

};

void dopass_typecheck(Program_ptr ast, SymTab *st) {
  Typecheck* typecheck = new Typecheck(stderr, st); //create the visitor
  ast->accept(typecheck); //walk the tree with the visitor above
  // st->dump(stdout);
  delete typecheck;
}

