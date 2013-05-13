#ifndef AST_HEADER
#define AST_HEADER

//Automatically Generated C++ Abstract Syntax Tree Interface

using namespace std;
#include <list>
#include "attribute.hpp"


/********** Forward Declarations **********/

class ProgramImpl;
class Program;
class FuncImpl;
class Func;
class FuncBlockImpl;
class FuncBlock;
class StatBlockImpl;
class StatBlock;
class DeclImpl;
class Decl;
class Assignment;
class Stat;
class ArrayAssignment;
class Call;
class ArrayCall;
class IfNoElse;
class IfWithElse;
class WhileLoop;
class Yield;
class ReturnImpl;
class Return;
class TInteger;
class Type;
class TBoolean;
class TRational;
class TAuto;
class TIntArray;
class And;
class Expr;
class Div;
class Compare;
class Gt;
class Gteq;
class Lt;
class Lteq;
class Minus;
class Noteq;
class Or;
class Plus;
class Times;
class Not;
class Uminus;
class Ident;
class ArrayAccess;
class IntLit;
class BoolLit;
class RatLit;
class SymName;
class Primitive;


/********** Pointer Typedefs **********/

typedef Program* Program_ptr;

typedef Func* Func_ptr;
typedef Decl* Decl_ptr;
typedef Stat* Stat_ptr;
typedef SymName* SymName_ptr;
typedef Expr* Expr_ptr;


/********** Union Type (from parse) **********/

#ifdef YYSTYPE_IS_TRIVIAL
#error Make sure to include this file _before_ parser.hpp
#endif
typedef union
{
list<Func_ptr>* u_func_list;
Program* u_program;
list<Decl_ptr>* u_decl_list;
Func* u_func;
list<Stat_ptr>* u_stat_list;
FuncBlock* u_funcblock;
StatBlock* u_statblock;
list<SymName_ptr>* u_symname_list;
Decl* u_decl;
Stat* u_stat;
list<Expr_ptr>* u_expr_list;
Return* u_return;
Type* u_type;
Expr* u_expr;
SymName* u_symname;
Primitive* u_primitive;

// a couple of hardcoded types
char* u_base_charptr;
int u_base_int;
} classunion_stype;
#define YYSTYPE classunion_stype

/********** Visitor Interfaces **********/

class Visitor{
 public:
  virtual ~Visitor() {}
  virtual void visitProgramImpl(ProgramImpl *p) = 0;
  virtual void visitFuncImpl(FuncImpl *p) = 0;
  virtual void visitFuncBlockImpl(FuncBlockImpl *p) = 0;
  virtual void visitStatBlockImpl(StatBlockImpl *p) = 0;
  virtual void visitDeclImpl(DeclImpl *p) = 0;
  virtual void visitAssignment(Assignment *p) = 0;
  virtual void visitArrayAssignment(ArrayAssignment *p) = 0;
  virtual void visitCall(Call *p) = 0;
  virtual void visitArrayCall(ArrayCall *p) = 0;
  virtual void visitIfNoElse(IfNoElse *p) = 0;
  virtual void visitIfWithElse(IfWithElse *p) = 0;
  virtual void visitWhileLoop(WhileLoop *p) = 0;
  virtual void visitYield(Yield *p) = 0;
  virtual void visitReturnImpl(ReturnImpl *p) = 0;
  virtual void visitTInteger(TInteger *p) = 0;
  virtual void visitTBoolean(TBoolean *p) = 0;
  virtual void visitTRational(TRational *p) = 0;
  virtual void visitTAuto(TAuto *p) = 0;
  virtual void visitTIntArray(TIntArray *p) = 0;
  virtual void visitAnd(And *p) = 0;
  virtual void visitDiv(Div *p) = 0;
  virtual void visitCompare(Compare *p) = 0;
  virtual void visitGt(Gt *p) = 0;
  virtual void visitGteq(Gteq *p) = 0;
  virtual void visitLt(Lt *p) = 0;
  virtual void visitLteq(Lteq *p) = 0;
  virtual void visitMinus(Minus *p) = 0;
  virtual void visitNoteq(Noteq *p) = 0;
  virtual void visitOr(Or *p) = 0;
  virtual void visitPlus(Plus *p) = 0;
  virtual void visitTimes(Times *p) = 0;
  virtual void visitNot(Not *p) = 0;
  virtual void visitUminus(Uminus *p) = 0;
  virtual void visitIdent(Ident *p) = 0;
  virtual void visitArrayAccess(ArrayAccess *p) = 0;
  virtual void visitIntLit(IntLit *p) = 0;
  virtual void visitBoolLit(BoolLit *p) = 0;
  virtual void visitRatLit(RatLit *p) = 0;
  virtual void visitSymName(SymName *p) = 0;
  virtual void visitPrimitive(Primitive *p) = 0;

  virtual void visitNullPointer() {}
};

class Visitable
{
 public:
  virtual ~Visitable() {}
  virtual void visit_children(Visitor *v) = 0;
  virtual void accept(Visitor *v) = 0;
};


/********** Abstract Syntax Classes **********/

class Program : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Program *clone() const = 0;
};

class Func : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Func *clone() const = 0;
};

class FuncBlock : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual FuncBlock *clone() const = 0;
};

class StatBlock : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual StatBlock *clone() const = 0;
};

class Decl : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Decl *clone() const = 0;
};

class Stat : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Stat *clone() const = 0;
};

class Return : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Return *clone() const = 0;
};

class Type : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Type *clone() const = 0;
};

class Expr : public Visitable {
public:
   Attribute m_attribute;
   Attribute* m_parent_attribute;
   virtual Expr *clone() const = 0;
};


// Program ==> *Func
class ProgramImpl : public Program
{
  public:
  list<Func_ptr> *m_func_list;

  ProgramImpl(const ProgramImpl &);
  ProgramImpl &operator=(const ProgramImpl &);
  ProgramImpl(list<Func_ptr> *p1);
  ~ProgramImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ProgramImpl  *clone() const;
  void swap(ProgramImpl &);
};

// Func ==>  SymName *Decl Type FuncBlock
class FuncImpl : public Func
{
  public:
  SymName *m_symname;
  list<Decl_ptr> *m_decl_list;
  Type *m_type;
  FuncBlock *m_funcblock;

  FuncImpl(const FuncImpl &);
  FuncImpl &operator=(const FuncImpl &);
  FuncImpl(SymName *p1, list<Decl_ptr> *p2, Type *p3, FuncBlock *p4);
  ~FuncImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  FuncImpl  *clone() const;
  void swap(FuncImpl &);
};

// FuncBlock ==> *Decl *Func *Stat Return
class FuncBlockImpl : public FuncBlock
{
  public:
  list<Decl_ptr> *m_decl_list;
  list<Func_ptr> *m_func_list;
  list<Stat_ptr> *m_stat_list;
  Return *m_return;

  FuncBlockImpl(const FuncBlockImpl &);
  FuncBlockImpl &operator=(const FuncBlockImpl &);
  FuncBlockImpl(list<Decl_ptr> *p1, list<Func_ptr> *p2, list<Stat_ptr> *p3, Return *p4);
  ~FuncBlockImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  FuncBlockImpl  *clone() const;
  void swap(FuncBlockImpl &);
};

// StatBlock ==> *Stat
class StatBlockImpl : public StatBlock
{
  public:
  list<Stat_ptr> *m_stat_list;

  StatBlockImpl(const StatBlockImpl &);
  StatBlockImpl &operator=(const StatBlockImpl &);
  StatBlockImpl(list<Stat_ptr> *p1);
  ~StatBlockImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  StatBlockImpl  *clone() const;
  void swap(StatBlockImpl &);
};

// Decl ==> *SymName Type
class DeclImpl : public Decl
{
  public:
  list<SymName_ptr> *m_symname_list;
  Type *m_type;

  DeclImpl(const DeclImpl &);
  DeclImpl &operator=(const DeclImpl &);
  DeclImpl(list<SymName_ptr> *p1, Type *p2);
  ~DeclImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  DeclImpl  *clone() const;
  void swap(DeclImpl &);
};

// Stat:Assignment ==> SymName Expr
class Assignment : public Stat
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  Assignment(const Assignment &);
  Assignment &operator=(const Assignment &);
  Assignment(SymName *p1, Expr *p2);
  ~Assignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Assignment  *clone() const;
  void swap(Assignment &);
};

// Stat:ArrayAssignment ==> SymName Expr Expr
class ArrayAssignment : public Stat
{
  public:
  SymName *m_symname;
  Expr *m_expr_1;
  Expr *m_expr_2;

  ArrayAssignment(const ArrayAssignment &);
  ArrayAssignment &operator=(const ArrayAssignment &);
  ArrayAssignment(SymName *p1, Expr *p2, Expr *p3);
  ~ArrayAssignment();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ArrayAssignment  *clone() const;
  void swap(ArrayAssignment &);
};

// Stat:Call ==> SymName SymName *Expr 
class Call : public Stat
{
  public:
  SymName *m_symname_1;
  SymName *m_symname_2;
  list<Expr_ptr> *m_expr_list;

  Call(const Call &);
  Call &operator=(const Call &);
  Call(SymName *p1, SymName *p2, list<Expr_ptr> *p3);
  ~Call();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Call  *clone() const;
  void swap(Call &);
};

// Stat:ArrayCall ==> SymName Expr SymName *Expr
class ArrayCall : public Stat
{
  public:
  SymName *m_symname_1;
  Expr *m_expr_1;
  SymName *m_symname_2;
  list<Expr_ptr> *m_expr_list_2;

  ArrayCall(const ArrayCall &);
  ArrayCall &operator=(const ArrayCall &);
  ArrayCall(SymName *p1, Expr *p2, SymName *p3, list<Expr_ptr> *p4);
  ~ArrayCall();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ArrayCall  *clone() const;
  void swap(ArrayCall &);
};

// Stat:IfNoElse ==> Expr StatBlock
class IfNoElse : public Stat
{
  public:
  Expr *m_expr;
  StatBlock *m_statblock;

  IfNoElse(const IfNoElse &);
  IfNoElse &operator=(const IfNoElse &);
  IfNoElse(Expr *p1, StatBlock *p2);
  ~IfNoElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IfNoElse  *clone() const;
  void swap(IfNoElse &);
};

// Stat:IfWithElse ==> Expr StatBlock StatBlock
class IfWithElse : public Stat
{
  public:
  Expr *m_expr;
  StatBlock *m_statblock_1;
  StatBlock *m_statblock_2;

  IfWithElse(const IfWithElse &);
  IfWithElse &operator=(const IfWithElse &);
  IfWithElse(Expr *p1, StatBlock *p2, StatBlock *p3);
  ~IfWithElse();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IfWithElse  *clone() const;
  void swap(IfWithElse &);
};

// Stat:WhileLoop ==> Expr StatBlock
class WhileLoop : public Stat
{
  public:
  Expr *m_expr;
  StatBlock *m_statblock;

  WhileLoop(const WhileLoop &);
  WhileLoop &operator=(const WhileLoop &);
  WhileLoop(Expr *p1, StatBlock *p2);
  ~WhileLoop();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  WhileLoop  *clone() const;
  void swap(WhileLoop &);
};

// Stat:Yield ==> Expr 
class Yield : public Stat
{
  public:
  Expr *m_expr;

  Yield(const Yield &);
  Yield &operator=(const Yield &);
  Yield(Expr *p1);
  ~Yield();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Yield  *clone() const;
  void swap(Yield &);
};

// Return ==> Expr
class ReturnImpl : public Return
{
  public:
  Expr *m_expr;

  ReturnImpl(const ReturnImpl &);
  ReturnImpl &operator=(const ReturnImpl &);
  ReturnImpl(Expr *p1);
  ~ReturnImpl();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ReturnImpl  *clone() const;
  void swap(ReturnImpl &);
};

// Type:TInteger ==> 
class TInteger : public Type
{
  public:

  TInteger(const TInteger &);
  TInteger &operator=(const TInteger &);
  TInteger();
  ~TInteger();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TInteger  *clone() const;
  void swap(TInteger &);
};

// Type:TBoolean ==> 
class TBoolean : public Type
{
  public:

  TBoolean(const TBoolean &);
  TBoolean &operator=(const TBoolean &);
  TBoolean();
  ~TBoolean();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TBoolean  *clone() const;
  void swap(TBoolean &);
};

// Type:TRational ==> 
class TRational : public Type
{
  public:

  TRational(const TRational &);
  TRational &operator=(const TRational &);
  TRational();
  ~TRational();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TRational  *clone() const;
  void swap(TRational &);
};

// Type:TAuto ==> 
class TAuto : public Type
{
  public:

  TAuto(const TAuto &);
  TAuto &operator=(const TAuto &);
  TAuto();
  ~TAuto();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TAuto  *clone() const;
  void swap(TAuto &);
};

// Type:TIntArray ==> Primitive
class TIntArray : public Type
{
  public:
  Primitive *m_primitive;

  TIntArray(const TIntArray &);
  TIntArray &operator=(const TIntArray &);
  TIntArray(Primitive *p1);
  ~TIntArray();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  TIntArray  *clone() const;
  void swap(TIntArray &);
};

// Expr:And ==> Expr Expr
class And : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  And(const And &);
  And &operator=(const And &);
  And(Expr *p1, Expr *p2);
  ~And();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  And  *clone() const;
  void swap(And &);
};

// Expr:Div ==> Expr Expr
class Div : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Div(const Div &);
  Div &operator=(const Div &);
  Div(Expr *p1, Expr *p2);
  ~Div();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Div  *clone() const;
  void swap(Div &);
};

// Expr:Compare ==> Expr Expr
class Compare : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Compare(const Compare &);
  Compare &operator=(const Compare &);
  Compare(Expr *p1, Expr *p2);
  ~Compare();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Compare  *clone() const;
  void swap(Compare &);
};

// Expr:Gt ==> Expr Expr
class Gt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gt(const Gt &);
  Gt &operator=(const Gt &);
  Gt(Expr *p1, Expr *p2);
  ~Gt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Gt  *clone() const;
  void swap(Gt &);
};

// Expr:Gteq ==> Expr Expr
class Gteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Gteq(const Gteq &);
  Gteq &operator=(const Gteq &);
  Gteq(Expr *p1, Expr *p2);
  ~Gteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Gteq  *clone() const;
  void swap(Gteq &);
};

// Expr:Lt ==> Expr Expr
class Lt : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lt(const Lt &);
  Lt &operator=(const Lt &);
  Lt(Expr *p1, Expr *p2);
  ~Lt();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Lt  *clone() const;
  void swap(Lt &);
};

// Expr:Lteq ==> Expr Expr
class Lteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Lteq(const Lteq &);
  Lteq &operator=(const Lteq &);
  Lteq(Expr *p1, Expr *p2);
  ~Lteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Lteq  *clone() const;
  void swap(Lteq &);
};

// Expr:Minus ==> Expr Expr
class Minus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Minus(const Minus &);
  Minus &operator=(const Minus &);
  Minus(Expr *p1, Expr *p2);
  ~Minus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Minus  *clone() const;
  void swap(Minus &);
};

// Expr:Noteq ==> Expr Expr
class Noteq : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Noteq(const Noteq &);
  Noteq &operator=(const Noteq &);
  Noteq(Expr *p1, Expr *p2);
  ~Noteq();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Noteq  *clone() const;
  void swap(Noteq &);
};

// Expr:Or ==> Expr Expr
class Or : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Or(const Or &);
  Or &operator=(const Or &);
  Or(Expr *p1, Expr *p2);
  ~Or();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Or  *clone() const;
  void swap(Or &);
};

// Expr:Plus ==> Expr Expr
class Plus : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Plus(const Plus &);
  Plus &operator=(const Plus &);
  Plus(Expr *p1, Expr *p2);
  ~Plus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Plus  *clone() const;
  void swap(Plus &);
};

// Expr:Times ==> Expr Expr
class Times : public Expr
{
  public:
  Expr *m_expr_1;
  Expr *m_expr_2;

  Times(const Times &);
  Times &operator=(const Times &);
  Times(Expr *p1, Expr *p2);
  ~Times();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Times  *clone() const;
  void swap(Times &);
};

// Expr:Not ==> Expr
class Not : public Expr
{
  public:
  Expr *m_expr;

  Not(const Not &);
  Not &operator=(const Not &);
  Not(Expr *p1);
  ~Not();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Not  *clone() const;
  void swap(Not &);
};

// Expr:Uminus ==> Expr
class Uminus : public Expr
{
  public:
  Expr *m_expr;

  Uminus(const Uminus &);
  Uminus &operator=(const Uminus &);
  Uminus(Expr *p1);
  ~Uminus();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Uminus  *clone() const;
  void swap(Uminus &);
};

// Expr:Ident ==> SymName
class Ident : public Expr
{
  public:
  SymName *m_symname;

  Ident(const Ident &);
  Ident &operator=(const Ident &);
  Ident(SymName *p1);
  ~Ident();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  Ident  *clone() const;
  void swap(Ident &);
};

// Expr:ArrayAccess ==> SymName Expr
class ArrayAccess : public Expr
{
  public:
  SymName *m_symname;
  Expr *m_expr;

  ArrayAccess(const ArrayAccess &);
  ArrayAccess &operator=(const ArrayAccess &);
  ArrayAccess(SymName *p1, Expr *p2);
  ~ArrayAccess();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  ArrayAccess  *clone() const;
  void swap(ArrayAccess &);
};

// Expr:IntLit ==> Primitive
class IntLit : public Expr
{
  public:
  Primitive *m_primitive;

  IntLit(const IntLit &);
  IntLit &operator=(const IntLit &);
  IntLit(Primitive *p1);
  ~IntLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  IntLit  *clone() const;
  void swap(IntLit &);
};

// Expr:BoolLit ==> Primitive
class BoolLit : public Expr
{
  public:
  Primitive *m_primitive;

  BoolLit(const BoolLit &);
  BoolLit &operator=(const BoolLit &);
  BoolLit(Primitive *p1);
  ~BoolLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  BoolLit  *clone() const;
  void swap(BoolLit &);
};

// Expr:RatLit ==> Primitive Primitive
class RatLit : public Expr
{
  public:
  Primitive *m_primitive_1;
  Primitive *m_primitive_2;

  RatLit(const RatLit &);
  RatLit &operator=(const RatLit &);
  RatLit(Primitive *p1, Primitive *p2);
  ~RatLit();
  virtual void visit_children( Visitor* v );
  virtual void accept(Visitor *v);
  virtual  RatLit  *clone() const;
  void swap(RatLit &);
};




#endif //AST_HEADER

