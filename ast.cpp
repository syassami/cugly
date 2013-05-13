//Automatically Generated C++ Abstract Syntax Tree Class Hierarchy

#include <algorithm>
#include "ast.hpp"
extern int yylineno;
#include "symtab.hpp"
#include "primitive.hpp"



/********* ProgramImpl ************/
 ProgramImpl::ProgramImpl(list<Func_ptr> *p1)  {
	m_func_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  if(*m_func_list_iter != NULL) {
		    (*m_func_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
 }
 ProgramImpl::ProgramImpl(const ProgramImpl & other) {
	if (m_func_list != NULL) {
	  m_func_list = new list<Func_ptr>;
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = other.m_func_list->begin();
	    m_func_list_iter != other.m_func_list->end();
	    ++m_func_list_iter){
		  m_func_list->push_back( (*m_func_list_iter)->clone() );
	  }
	}
 }
 ProgramImpl &ProgramImpl::operator=(const ProgramImpl & other) { ProgramImpl tmp(other); swap(tmp); return *this; }
 void ProgramImpl::swap(ProgramImpl & other) {
	std::swap(m_func_list, other.m_func_list);
 }
 ProgramImpl::~ProgramImpl() {
 	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  delete( *m_func_list_iter );
	  }
	}
 }
 void ProgramImpl::visit_children( Visitor* v ) {
 	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  if(*m_func_list_iter != NULL) {
		    (*m_func_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
 }
 void ProgramImpl::accept(Visitor *v) { v->visitProgramImpl(this); }
 ProgramImpl *ProgramImpl::clone() const { return new ProgramImpl(*this); }
 
 
/********* FuncImpl ************/
 FuncImpl::FuncImpl(SymName *p1, list<Decl_ptr> *p2, Type *p3, FuncBlock *p4)  {
	m_symname = p1;
	m_decl_list = p2;
	m_type = p3;
	m_funcblock = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname != NULL) {
	  m_symname->m_parent_attribute = &m_attribute;
 	}
	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  if(*m_decl_list_iter != NULL) {
		    (*m_decl_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
	if (m_type != NULL) {
	  m_type->m_parent_attribute = &m_attribute;
 	}
	if (m_funcblock != NULL) {
	  m_funcblock->m_parent_attribute = &m_attribute;
 	}
 }
 FuncImpl::FuncImpl(const FuncImpl & other) {
	if (m_symname != NULL) {
	  m_symname = other.m_symname->clone();
	}
	if (m_decl_list != NULL) {
	  m_decl_list = new list<Decl_ptr>;
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = other.m_decl_list->begin();
	    m_decl_list_iter != other.m_decl_list->end();
	    ++m_decl_list_iter){
		  m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	  }
	}
	if (m_type != NULL) {
	  m_type = other.m_type->clone();
	}
	if (m_funcblock != NULL) {
	  m_funcblock = other.m_funcblock->clone();
	}
 }
 FuncImpl &FuncImpl::operator=(const FuncImpl & other) { FuncImpl tmp(other); swap(tmp); return *this; }
 void FuncImpl::swap(FuncImpl & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_type, other.m_type);
	std::swap(m_funcblock, other.m_funcblock);
 }
 FuncImpl::~FuncImpl() {
 	if (m_symname != NULL) {
	  delete(m_symname);
 	}
	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  delete( *m_decl_list_iter );
	  }
	}
	if (m_type != NULL) {
	  delete(m_type);
 	}
	if (m_funcblock != NULL) {
	  delete(m_funcblock);
 	}
 }
 void FuncImpl::visit_children( Visitor* v ) {
 	if (m_symname != NULL) {
	  m_symname->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  if(*m_decl_list_iter != NULL) {
		    (*m_decl_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
	if (m_type != NULL) {
	  m_type->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_funcblock != NULL) {
	  m_funcblock->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void FuncImpl::accept(Visitor *v) { v->visitFuncImpl(this); }
 FuncImpl *FuncImpl::clone() const { return new FuncImpl(*this); }
 
 
/********* FuncBlockImpl ************/
 FuncBlockImpl::FuncBlockImpl(list<Decl_ptr> *p1, list<Func_ptr> *p2, list<Stat_ptr> *p3, Return *p4)  {
	m_decl_list = p1;
	m_func_list = p2;
	m_stat_list = p3;
	m_return = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  if(*m_decl_list_iter != NULL) {
		    (*m_decl_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  if(*m_func_list_iter != NULL) {
		    (*m_func_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  if(*m_stat_list_iter != NULL) {
		    (*m_stat_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
	if (m_return != NULL) {
	  m_return->m_parent_attribute = &m_attribute;
 	}
 }
 FuncBlockImpl::FuncBlockImpl(const FuncBlockImpl & other) {
	if (m_decl_list != NULL) {
	  m_decl_list = new list<Decl_ptr>;
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = other.m_decl_list->begin();
	    m_decl_list_iter != other.m_decl_list->end();
	    ++m_decl_list_iter){
		  m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	  }
	}
	if (m_func_list != NULL) {
	  m_func_list = new list<Func_ptr>;
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = other.m_func_list->begin();
	    m_func_list_iter != other.m_func_list->end();
	    ++m_func_list_iter){
		  m_func_list->push_back( (*m_func_list_iter)->clone() );
	  }
	}
	if (m_stat_list != NULL) {
	  m_stat_list = new list<Stat_ptr>;
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = other.m_stat_list->begin();
	    m_stat_list_iter != other.m_stat_list->end();
	    ++m_stat_list_iter){
		  m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	  }
	}
	if (m_return != NULL) {
	  m_return = other.m_return->clone();
	}
 }
 FuncBlockImpl &FuncBlockImpl::operator=(const FuncBlockImpl & other) { FuncBlockImpl tmp(other); swap(tmp); return *this; }
 void FuncBlockImpl::swap(FuncBlockImpl & other) {
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_func_list, other.m_func_list);
	std::swap(m_stat_list, other.m_stat_list);
	std::swap(m_return, other.m_return);
 }
 FuncBlockImpl::~FuncBlockImpl() {
 	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  delete( *m_decl_list_iter );
	  }
	}
	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  delete( *m_func_list_iter );
	  }
	}
	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  delete( *m_stat_list_iter );
	  }
	}
	if (m_return != NULL) {
	  delete(m_return);
 	}
 }
 void FuncBlockImpl::visit_children( Visitor* v ) {
 	if (m_decl_list != NULL) {
	  list<Decl_ptr>::iterator m_decl_list_iter;
	  for(m_decl_list_iter = m_decl_list->begin();
	    m_decl_list_iter != m_decl_list->end();
	    ++m_decl_list_iter){
		  if(*m_decl_list_iter != NULL) {
		    (*m_decl_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
	if (m_func_list != NULL) {
	  list<Func_ptr>::iterator m_func_list_iter;
	  for(m_func_list_iter = m_func_list->begin();
	    m_func_list_iter != m_func_list->end();
	    ++m_func_list_iter){
		  if(*m_func_list_iter != NULL) {
		    (*m_func_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  if(*m_stat_list_iter != NULL) {
		    (*m_stat_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
	if (m_return != NULL) {
	  m_return->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void FuncBlockImpl::accept(Visitor *v) { v->visitFuncBlockImpl(this); }
 FuncBlockImpl *FuncBlockImpl::clone() const { return new FuncBlockImpl(*this); }
 
 
/********* StatBlockImpl ************/
 StatBlockImpl::StatBlockImpl(list<Stat_ptr> *p1)  {
	m_stat_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  if(*m_stat_list_iter != NULL) {
		    (*m_stat_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
 }
 StatBlockImpl::StatBlockImpl(const StatBlockImpl & other) {
	if (m_stat_list != NULL) {
	  m_stat_list = new list<Stat_ptr>;
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = other.m_stat_list->begin();
	    m_stat_list_iter != other.m_stat_list->end();
	    ++m_stat_list_iter){
		  m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	  }
	}
 }
 StatBlockImpl &StatBlockImpl::operator=(const StatBlockImpl & other) { StatBlockImpl tmp(other); swap(tmp); return *this; }
 void StatBlockImpl::swap(StatBlockImpl & other) {
	std::swap(m_stat_list, other.m_stat_list);
 }
 StatBlockImpl::~StatBlockImpl() {
 	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  delete( *m_stat_list_iter );
	  }
	}
 }
 void StatBlockImpl::visit_children( Visitor* v ) {
 	if (m_stat_list != NULL) {
	  list<Stat_ptr>::iterator m_stat_list_iter;
	  for(m_stat_list_iter = m_stat_list->begin();
	    m_stat_list_iter != m_stat_list->end();
	    ++m_stat_list_iter){
		  if(*m_stat_list_iter != NULL) {
		    (*m_stat_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
 }
 void StatBlockImpl::accept(Visitor *v) { v->visitStatBlockImpl(this); }
 StatBlockImpl *StatBlockImpl::clone() const { return new StatBlockImpl(*this); }
 
 
/********* DeclImpl ************/
 DeclImpl::DeclImpl(list<SymName_ptr> *p1, Type *p2)  {
	m_symname_list = p1;
	m_type = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname_list != NULL) {
	  list<SymName_ptr>::iterator m_symname_list_iter;
	  for(m_symname_list_iter = m_symname_list->begin();
	    m_symname_list_iter != m_symname_list->end();
	    ++m_symname_list_iter){
		  if(*m_symname_list_iter != NULL) {
		    (*m_symname_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
	if (m_type != NULL) {
	  m_type->m_parent_attribute = &m_attribute;
 	}
 }
 DeclImpl::DeclImpl(const DeclImpl & other) {
	if (m_symname_list != NULL) {
	  m_symname_list = new list<SymName_ptr>;
	  list<SymName_ptr>::iterator m_symname_list_iter;
	  for(m_symname_list_iter = other.m_symname_list->begin();
	    m_symname_list_iter != other.m_symname_list->end();
	    ++m_symname_list_iter){
		  m_symname_list->push_back( (*m_symname_list_iter)->clone() );
	  }
	}
	if (m_type != NULL) {
	  m_type = other.m_type->clone();
	}
 }
 DeclImpl &DeclImpl::operator=(const DeclImpl & other) { DeclImpl tmp(other); swap(tmp); return *this; }
 void DeclImpl::swap(DeclImpl & other) {
	std::swap(m_symname_list, other.m_symname_list);
	std::swap(m_type, other.m_type);
 }
 DeclImpl::~DeclImpl() {
 	if (m_symname_list != NULL) {
	  list<SymName_ptr>::iterator m_symname_list_iter;
	  for(m_symname_list_iter = m_symname_list->begin();
	    m_symname_list_iter != m_symname_list->end();
	    ++m_symname_list_iter){
		  delete( *m_symname_list_iter );
	  }
	}
	if (m_type != NULL) {
	  delete(m_type);
 	}
 }
 void DeclImpl::visit_children( Visitor* v ) {
 	if (m_symname_list != NULL) {
	  list<SymName_ptr>::iterator m_symname_list_iter;
	  for(m_symname_list_iter = m_symname_list->begin();
	    m_symname_list_iter != m_symname_list->end();
	    ++m_symname_list_iter){
		  if(*m_symname_list_iter != NULL) {
		    (*m_symname_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
	if (m_type != NULL) {
	  m_type->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void DeclImpl::accept(Visitor *v) { v->visitDeclImpl(this); }
 DeclImpl *DeclImpl::clone() const { return new DeclImpl(*this); }
 
 
/********* Assignment ************/
 Assignment::Assignment(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname != NULL) {
	  m_symname->m_parent_attribute = &m_attribute;
 	}
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 Assignment::Assignment(const Assignment & other) {
	if (m_symname != NULL) {
	  m_symname = other.m_symname->clone();
	}
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 Assignment &Assignment::operator=(const Assignment & other) { Assignment tmp(other); swap(tmp); return *this; }
 void Assignment::swap(Assignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 Assignment::~Assignment() {
 	if (m_symname != NULL) {
	  delete(m_symname);
 	}
	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void Assignment::visit_children( Visitor* v ) {
 	if (m_symname != NULL) {
	  m_symname->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Assignment::accept(Visitor *v) { v->visitAssignment(this); }
 Assignment *Assignment::clone() const { return new Assignment(*this); }
 
 
/********* ArrayAssignment ************/
 ArrayAssignment::ArrayAssignment(SymName *p1, Expr *p2, Expr *p3)  {
	m_symname = p1;
	m_expr_1 = p2;
	m_expr_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname != NULL) {
	  m_symname->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 ArrayAssignment::ArrayAssignment(const ArrayAssignment & other) {
	if (m_symname != NULL) {
	  m_symname = other.m_symname->clone();
	}
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 ArrayAssignment &ArrayAssignment::operator=(const ArrayAssignment & other) { ArrayAssignment tmp(other); swap(tmp); return *this; }
 void ArrayAssignment::swap(ArrayAssignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 ArrayAssignment::~ArrayAssignment() {
 	if (m_symname != NULL) {
	  delete(m_symname);
 	}
	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void ArrayAssignment::visit_children( Visitor* v ) {
 	if (m_symname != NULL) {
	  m_symname->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void ArrayAssignment::accept(Visitor *v) { v->visitArrayAssignment(this); }
 ArrayAssignment *ArrayAssignment::clone() const { return new ArrayAssignment(*this); }
 
 
/********* Call ************/
 Call::Call(SymName *p1, SymName *p2, list<Expr_ptr> *p3)  {
	m_symname_1 = p1;
	m_symname_2 = p2;
	m_expr_list = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname_1 != NULL) {
	  m_symname_1->m_parent_attribute = &m_attribute;
 	}
	if (m_symname_2 != NULL) {
	  m_symname_2->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_list != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_iter;
	  for(m_expr_list_iter = m_expr_list->begin();
	    m_expr_list_iter != m_expr_list->end();
	    ++m_expr_list_iter){
		  if(*m_expr_list_iter != NULL) {
		    (*m_expr_list_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
 }
 Call::Call(const Call & other) {
	if (m_symname_1 != NULL) {
	  m_symname_1 = other.m_symname_1->clone();
	}
	if (m_symname_2 != NULL) {
	  m_symname_2 = other.m_symname_2->clone();
	}
	if (m_expr_list != NULL) {
	  m_expr_list = new list<Expr_ptr>;
	  list<Expr_ptr>::iterator m_expr_list_iter;
	  for(m_expr_list_iter = other.m_expr_list->begin();
	    m_expr_list_iter != other.m_expr_list->end();
	    ++m_expr_list_iter){
		  m_expr_list->push_back( (*m_expr_list_iter)->clone() );
	  }
	}
 }
 Call &Call::operator=(const Call & other) { Call tmp(other); swap(tmp); return *this; }
 void Call::swap(Call & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list, other.m_expr_list);
 }
 Call::~Call() {
 	if (m_symname_1 != NULL) {
	  delete(m_symname_1);
 	}
	if (m_symname_2 != NULL) {
	  delete(m_symname_2);
 	}
	if (m_expr_list != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_iter;
	  for(m_expr_list_iter = m_expr_list->begin();
	    m_expr_list_iter != m_expr_list->end();
	    ++m_expr_list_iter){
		  delete( *m_expr_list_iter );
	  }
	}
 }
 void Call::visit_children( Visitor* v ) {
 	if (m_symname_1 != NULL) {
	  m_symname_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_symname_2 != NULL) {
	  m_symname_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_list != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_iter;
	  for(m_expr_list_iter = m_expr_list->begin();
	    m_expr_list_iter != m_expr_list->end();
	    ++m_expr_list_iter){
		  if(*m_expr_list_iter != NULL) {
		    (*m_expr_list_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
 }
 void Call::accept(Visitor *v) { v->visitCall(this); }
 Call *Call::clone() const { return new Call(*this); }
 
 
/********* ArrayCall ************/
 ArrayCall::ArrayCall(SymName *p1, Expr *p2, SymName *p3, list<Expr_ptr> *p4)  {
	m_symname_1 = p1;
	m_expr_1 = p2;
	m_symname_2 = p3;
	m_expr_list_2 = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname_1 != NULL) {
	  m_symname_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_symname_2 != NULL) {
	  m_symname_2->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_list_2 != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_2_iter;
	  for(m_expr_list_2_iter = m_expr_list_2->begin();
	    m_expr_list_2_iter != m_expr_list_2->end();
	    ++m_expr_list_2_iter){
		  if(*m_expr_list_2_iter != NULL) {
		    (*m_expr_list_2_iter)->m_parent_attribute = &m_attribute;
		  }
	  }
	}
 }
 ArrayCall::ArrayCall(const ArrayCall & other) {
	if (m_symname_1 != NULL) {
	  m_symname_1 = other.m_symname_1->clone();
	}
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_symname_2 != NULL) {
	  m_symname_2 = other.m_symname_2->clone();
	}
	if (m_expr_list_2 != NULL) {
	  m_expr_list_2 = new list<Expr_ptr>;
	  list<Expr_ptr>::iterator m_expr_list_2_iter;
	  for(m_expr_list_2_iter = other.m_expr_list_2->begin();
	    m_expr_list_2_iter != other.m_expr_list_2->end();
	    ++m_expr_list_2_iter){
		  m_expr_list_2->push_back( (*m_expr_list_2_iter)->clone() );
	  }
	}
 }
 ArrayCall &ArrayCall::operator=(const ArrayCall & other) { ArrayCall tmp(other); swap(tmp); return *this; }
 void ArrayCall::swap(ArrayCall & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list_2, other.m_expr_list_2);
 }
 ArrayCall::~ArrayCall() {
 	if (m_symname_1 != NULL) {
	  delete(m_symname_1);
 	}
	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_symname_2 != NULL) {
	  delete(m_symname_2);
 	}
	if (m_expr_list_2 != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_2_iter;
	  for(m_expr_list_2_iter = m_expr_list_2->begin();
	    m_expr_list_2_iter != m_expr_list_2->end();
	    ++m_expr_list_2_iter){
		  delete( *m_expr_list_2_iter );
	  }
	}
 }
 void ArrayCall::visit_children( Visitor* v ) {
 	if (m_symname_1 != NULL) {
	  m_symname_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_symname_2 != NULL) {
	  m_symname_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_list_2 != NULL) {
	  list<Expr_ptr>::iterator m_expr_list_2_iter;
	  for(m_expr_list_2_iter = m_expr_list_2->begin();
	    m_expr_list_2_iter != m_expr_list_2->end();
	    ++m_expr_list_2_iter){
		  if(*m_expr_list_2_iter != NULL) {
		    (*m_expr_list_2_iter)->accept( v );
		  } else {
		    v->visitNullPointer();
		  }
	  }
	} else {
		v->visitNullPointer();
	}
 }
 void ArrayCall::accept(Visitor *v) { v->visitArrayCall(this); }
 ArrayCall *ArrayCall::clone() const { return new ArrayCall(*this); }
 
 
/********* IfNoElse ************/
 IfNoElse::IfNoElse(Expr *p1, StatBlock *p2)  {
	m_expr = p1;
	m_statblock = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
	if (m_statblock != NULL) {
	  m_statblock->m_parent_attribute = &m_attribute;
 	}
 }
 IfNoElse::IfNoElse(const IfNoElse & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
	if (m_statblock != NULL) {
	  m_statblock = other.m_statblock->clone();
	}
 }
 IfNoElse &IfNoElse::operator=(const IfNoElse & other) { IfNoElse tmp(other); swap(tmp); return *this; }
 void IfNoElse::swap(IfNoElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_statblock, other.m_statblock);
 }
 IfNoElse::~IfNoElse() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
	if (m_statblock != NULL) {
	  delete(m_statblock);
 	}
 }
 void IfNoElse::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_statblock != NULL) {
	  m_statblock->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void IfNoElse::accept(Visitor *v) { v->visitIfNoElse(this); }
 IfNoElse *IfNoElse::clone() const { return new IfNoElse(*this); }
 
 
/********* IfWithElse ************/
 IfWithElse::IfWithElse(Expr *p1, StatBlock *p2, StatBlock *p3)  {
	m_expr = p1;
	m_statblock_1 = p2;
	m_statblock_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
	if (m_statblock_1 != NULL) {
	  m_statblock_1->m_parent_attribute = &m_attribute;
 	}
	if (m_statblock_2 != NULL) {
	  m_statblock_2->m_parent_attribute = &m_attribute;
 	}
 }
 IfWithElse::IfWithElse(const IfWithElse & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
	if (m_statblock_1 != NULL) {
	  m_statblock_1 = other.m_statblock_1->clone();
	}
	if (m_statblock_2 != NULL) {
	  m_statblock_2 = other.m_statblock_2->clone();
	}
 }
 IfWithElse &IfWithElse::operator=(const IfWithElse & other) { IfWithElse tmp(other); swap(tmp); return *this; }
 void IfWithElse::swap(IfWithElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_statblock_1, other.m_statblock_1);
	std::swap(m_statblock_2, other.m_statblock_2);
 }
 IfWithElse::~IfWithElse() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
	if (m_statblock_1 != NULL) {
	  delete(m_statblock_1);
 	}
	if (m_statblock_2 != NULL) {
	  delete(m_statblock_2);
 	}
 }
 void IfWithElse::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_statblock_1 != NULL) {
	  m_statblock_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_statblock_2 != NULL) {
	  m_statblock_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void IfWithElse::accept(Visitor *v) { v->visitIfWithElse(this); }
 IfWithElse *IfWithElse::clone() const { return new IfWithElse(*this); }
 
 
/********* WhileLoop ************/
 WhileLoop::WhileLoop(Expr *p1, StatBlock *p2)  {
	m_expr = p1;
	m_statblock = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
	if (m_statblock != NULL) {
	  m_statblock->m_parent_attribute = &m_attribute;
 	}
 }
 WhileLoop::WhileLoop(const WhileLoop & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
	if (m_statblock != NULL) {
	  m_statblock = other.m_statblock->clone();
	}
 }
 WhileLoop &WhileLoop::operator=(const WhileLoop & other) { WhileLoop tmp(other); swap(tmp); return *this; }
 void WhileLoop::swap(WhileLoop & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_statblock, other.m_statblock);
 }
 WhileLoop::~WhileLoop() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
	if (m_statblock != NULL) {
	  delete(m_statblock);
 	}
 }
 void WhileLoop::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_statblock != NULL) {
	  m_statblock->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void WhileLoop::accept(Visitor *v) { v->visitWhileLoop(this); }
 WhileLoop *WhileLoop::clone() const { return new WhileLoop(*this); }
 
 
/********* Yield ************/
 Yield::Yield(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 Yield::Yield(const Yield & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 Yield &Yield::operator=(const Yield & other) { Yield tmp(other); swap(tmp); return *this; }
 void Yield::swap(Yield & other) {
	std::swap(m_expr, other.m_expr);
 }
 Yield::~Yield() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void Yield::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Yield::accept(Visitor *v) { v->visitYield(this); }
 Yield *Yield::clone() const { return new Yield(*this); }
 
 
/********* ReturnImpl ************/
 ReturnImpl::ReturnImpl(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 ReturnImpl::ReturnImpl(const ReturnImpl & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 ReturnImpl &ReturnImpl::operator=(const ReturnImpl & other) { ReturnImpl tmp(other); swap(tmp); return *this; }
 void ReturnImpl::swap(ReturnImpl & other) {
	std::swap(m_expr, other.m_expr);
 }
 ReturnImpl::~ReturnImpl() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void ReturnImpl::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void ReturnImpl::accept(Visitor *v) { v->visitReturnImpl(this); }
 ReturnImpl *ReturnImpl::clone() const { return new ReturnImpl(*this); }
 
 
/********* TInteger ************/
 TInteger::TInteger()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TInteger::TInteger(const TInteger & other) {
 }
 TInteger &TInteger::operator=(const TInteger & other) { TInteger tmp(other); swap(tmp); return *this; }
 void TInteger::swap(TInteger & other) {
 }
 TInteger::~TInteger() {
  }
 void TInteger::visit_children( Visitor* v ) {
  }
 void TInteger::accept(Visitor *v) { v->visitTInteger(this); }
 TInteger *TInteger::clone() const { return new TInteger(*this); }
 
 
/********* TBoolean ************/
 TBoolean::TBoolean()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TBoolean::TBoolean(const TBoolean & other) {
 }
 TBoolean &TBoolean::operator=(const TBoolean & other) { TBoolean tmp(other); swap(tmp); return *this; }
 void TBoolean::swap(TBoolean & other) {
 }
 TBoolean::~TBoolean() {
  }
 void TBoolean::visit_children( Visitor* v ) {
  }
 void TBoolean::accept(Visitor *v) { v->visitTBoolean(this); }
 TBoolean *TBoolean::clone() const { return new TBoolean(*this); }
 
 
/********* TRational ************/
 TRational::TRational()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TRational::TRational(const TRational & other) {
 }
 TRational &TRational::operator=(const TRational & other) { TRational tmp(other); swap(tmp); return *this; }
 void TRational::swap(TRational & other) {
 }
 TRational::~TRational() {
  }
 void TRational::visit_children( Visitor* v ) {
  }
 void TRational::accept(Visitor *v) { v->visitTRational(this); }
 TRational *TRational::clone() const { return new TRational(*this); }
 
 
/********* TAuto ************/
 TAuto::TAuto()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TAuto::TAuto(const TAuto & other) {
 }
 TAuto &TAuto::operator=(const TAuto & other) { TAuto tmp(other); swap(tmp); return *this; }
 void TAuto::swap(TAuto & other) {
 }
 TAuto::~TAuto() {
  }
 void TAuto::visit_children( Visitor* v ) {
  }
 void TAuto::accept(Visitor *v) { v->visitTAuto(this); }
 TAuto *TAuto::clone() const { return new TAuto(*this); }
 
 
/********* TIntArray ************/
 TIntArray::TIntArray(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_primitive != NULL) {
	  m_primitive->m_parent_attribute = &m_attribute;
 	}
 }
 TIntArray::TIntArray(const TIntArray & other) {
	if (m_primitive != NULL) {
	  m_primitive = other.m_primitive->clone();
	}
 }
 TIntArray &TIntArray::operator=(const TIntArray & other) { TIntArray tmp(other); swap(tmp); return *this; }
 void TIntArray::swap(TIntArray & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 TIntArray::~TIntArray() {
 	if (m_primitive != NULL) {
	  delete(m_primitive);
 	}
 }
 void TIntArray::visit_children( Visitor* v ) {
 	if (m_primitive != NULL) {
	  m_primitive->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void TIntArray::accept(Visitor *v) { v->visitTIntArray(this); }
 TIntArray *TIntArray::clone() const { return new TIntArray(*this); }
 
 
/********* And ************/
 And::And(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 And::And(const And & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 And &And::operator=(const And & other) { And tmp(other); swap(tmp); return *this; }
 void And::swap(And & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 And::~And() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void And::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void And::accept(Visitor *v) { v->visitAnd(this); }
 And *And::clone() const { return new And(*this); }
 
 
/********* Div ************/
 Div::Div(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Div::Div(const Div & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Div &Div::operator=(const Div & other) { Div tmp(other); swap(tmp); return *this; }
 void Div::swap(Div & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Div::~Div() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Div::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Div::accept(Visitor *v) { v->visitDiv(this); }
 Div *Div::clone() const { return new Div(*this); }
 
 
/********* Compare ************/
 Compare::Compare(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Compare::Compare(const Compare & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Compare &Compare::operator=(const Compare & other) { Compare tmp(other); swap(tmp); return *this; }
 void Compare::swap(Compare & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Compare::~Compare() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Compare::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Compare::accept(Visitor *v) { v->visitCompare(this); }
 Compare *Compare::clone() const { return new Compare(*this); }
 
 
/********* Gt ************/
 Gt::Gt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Gt::Gt(const Gt & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Gt &Gt::operator=(const Gt & other) { Gt tmp(other); swap(tmp); return *this; }
 void Gt::swap(Gt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gt::~Gt() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Gt::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Gt::accept(Visitor *v) { v->visitGt(this); }
 Gt *Gt::clone() const { return new Gt(*this); }
 
 
/********* Gteq ************/
 Gteq::Gteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Gteq::Gteq(const Gteq & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Gteq &Gteq::operator=(const Gteq & other) { Gteq tmp(other); swap(tmp); return *this; }
 void Gteq::swap(Gteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gteq::~Gteq() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Gteq::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Gteq::accept(Visitor *v) { v->visitGteq(this); }
 Gteq *Gteq::clone() const { return new Gteq(*this); }
 
 
/********* Lt ************/
 Lt::Lt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Lt::Lt(const Lt & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Lt &Lt::operator=(const Lt & other) { Lt tmp(other); swap(tmp); return *this; }
 void Lt::swap(Lt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lt::~Lt() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Lt::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Lt::accept(Visitor *v) { v->visitLt(this); }
 Lt *Lt::clone() const { return new Lt(*this); }
 
 
/********* Lteq ************/
 Lteq::Lteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Lteq::Lteq(const Lteq & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Lteq &Lteq::operator=(const Lteq & other) { Lteq tmp(other); swap(tmp); return *this; }
 void Lteq::swap(Lteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lteq::~Lteq() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Lteq::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Lteq::accept(Visitor *v) { v->visitLteq(this); }
 Lteq *Lteq::clone() const { return new Lteq(*this); }
 
 
/********* Minus ************/
 Minus::Minus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Minus::Minus(const Minus & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Minus &Minus::operator=(const Minus & other) { Minus tmp(other); swap(tmp); return *this; }
 void Minus::swap(Minus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Minus::~Minus() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Minus::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Minus::accept(Visitor *v) { v->visitMinus(this); }
 Minus *Minus::clone() const { return new Minus(*this); }
 
 
/********* Noteq ************/
 Noteq::Noteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Noteq::Noteq(const Noteq & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Noteq &Noteq::operator=(const Noteq & other) { Noteq tmp(other); swap(tmp); return *this; }
 void Noteq::swap(Noteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Noteq::~Noteq() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Noteq::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Noteq::accept(Visitor *v) { v->visitNoteq(this); }
 Noteq *Noteq::clone() const { return new Noteq(*this); }
 
 
/********* Or ************/
 Or::Or(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Or::Or(const Or & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Or &Or::operator=(const Or & other) { Or tmp(other); swap(tmp); return *this; }
 void Or::swap(Or & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Or::~Or() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Or::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Or::accept(Visitor *v) { v->visitOr(this); }
 Or *Or::clone() const { return new Or(*this); }
 
 
/********* Plus ************/
 Plus::Plus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Plus::Plus(const Plus & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Plus &Plus::operator=(const Plus & other) { Plus tmp(other); swap(tmp); return *this; }
 void Plus::swap(Plus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Plus::~Plus() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Plus::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Plus::accept(Visitor *v) { v->visitPlus(this); }
 Plus *Plus::clone() const { return new Plus(*this); }
 
 
/********* Times ************/
 Times::Times(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr_1 != NULL) {
	  m_expr_1->m_parent_attribute = &m_attribute;
 	}
	if (m_expr_2 != NULL) {
	  m_expr_2->m_parent_attribute = &m_attribute;
 	}
 }
 Times::Times(const Times & other) {
	if (m_expr_1 != NULL) {
	  m_expr_1 = other.m_expr_1->clone();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2 = other.m_expr_2->clone();
	}
 }
 Times &Times::operator=(const Times & other) { Times tmp(other); swap(tmp); return *this; }
 void Times::swap(Times & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Times::~Times() {
 	if (m_expr_1 != NULL) {
	  delete(m_expr_1);
 	}
	if (m_expr_2 != NULL) {
	  delete(m_expr_2);
 	}
 }
 void Times::visit_children( Visitor* v ) {
 	if (m_expr_1 != NULL) {
	  m_expr_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr_2 != NULL) {
	  m_expr_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Times::accept(Visitor *v) { v->visitTimes(this); }
 Times *Times::clone() const { return new Times(*this); }
 
 
/********* Not ************/
 Not::Not(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 Not::Not(const Not & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 Not &Not::operator=(const Not & other) { Not tmp(other); swap(tmp); return *this; }
 void Not::swap(Not & other) {
	std::swap(m_expr, other.m_expr);
 }
 Not::~Not() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void Not::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Not::accept(Visitor *v) { v->visitNot(this); }
 Not *Not::clone() const { return new Not(*this); }
 
 
/********* Uminus ************/
 Uminus::Uminus(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 Uminus::Uminus(const Uminus & other) {
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 Uminus &Uminus::operator=(const Uminus & other) { Uminus tmp(other); swap(tmp); return *this; }
 void Uminus::swap(Uminus & other) {
	std::swap(m_expr, other.m_expr);
 }
 Uminus::~Uminus() {
 	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void Uminus::visit_children( Visitor* v ) {
 	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Uminus::accept(Visitor *v) { v->visitUminus(this); }
 Uminus *Uminus::clone() const { return new Uminus(*this); }
 
 
/********* Ident ************/
 Ident::Ident(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname != NULL) {
	  m_symname->m_parent_attribute = &m_attribute;
 	}
 }
 Ident::Ident(const Ident & other) {
	if (m_symname != NULL) {
	  m_symname = other.m_symname->clone();
	}
 }
 Ident &Ident::operator=(const Ident & other) { Ident tmp(other); swap(tmp); return *this; }
 void Ident::swap(Ident & other) {
	std::swap(m_symname, other.m_symname);
 }
 Ident::~Ident() {
 	if (m_symname != NULL) {
	  delete(m_symname);
 	}
 }
 void Ident::visit_children( Visitor* v ) {
 	if (m_symname != NULL) {
	  m_symname->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void Ident::accept(Visitor *v) { v->visitIdent(this); }
 Ident *Ident::clone() const { return new Ident(*this); }
 
 
/********* ArrayAccess ************/
 ArrayAccess::ArrayAccess(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_symname != NULL) {
	  m_symname->m_parent_attribute = &m_attribute;
 	}
	if (m_expr != NULL) {
	  m_expr->m_parent_attribute = &m_attribute;
 	}
 }
 ArrayAccess::ArrayAccess(const ArrayAccess & other) {
	if (m_symname != NULL) {
	  m_symname = other.m_symname->clone();
	}
	if (m_expr != NULL) {
	  m_expr = other.m_expr->clone();
	}
 }
 ArrayAccess &ArrayAccess::operator=(const ArrayAccess & other) { ArrayAccess tmp(other); swap(tmp); return *this; }
 void ArrayAccess::swap(ArrayAccess & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 ArrayAccess::~ArrayAccess() {
 	if (m_symname != NULL) {
	  delete(m_symname);
 	}
	if (m_expr != NULL) {
	  delete(m_expr);
 	}
 }
 void ArrayAccess::visit_children( Visitor* v ) {
 	if (m_symname != NULL) {
	  m_symname->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_expr != NULL) {
	  m_expr->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void ArrayAccess::accept(Visitor *v) { v->visitArrayAccess(this); }
 ArrayAccess *ArrayAccess::clone() const { return new ArrayAccess(*this); }
 
 
/********* IntLit ************/
 IntLit::IntLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_primitive != NULL) {
	  m_primitive->m_parent_attribute = &m_attribute;
 	}
 }
 IntLit::IntLit(const IntLit & other) {
	if (m_primitive != NULL) {
	  m_primitive = other.m_primitive->clone();
	}
 }
 IntLit &IntLit::operator=(const IntLit & other) { IntLit tmp(other); swap(tmp); return *this; }
 void IntLit::swap(IntLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 IntLit::~IntLit() {
 	if (m_primitive != NULL) {
	  delete(m_primitive);
 	}
 }
 void IntLit::visit_children( Visitor* v ) {
 	if (m_primitive != NULL) {
	  m_primitive->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void IntLit::accept(Visitor *v) { v->visitIntLit(this); }
 IntLit *IntLit::clone() const { return new IntLit(*this); }
 
 
/********* BoolLit ************/
 BoolLit::BoolLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_primitive != NULL) {
	  m_primitive->m_parent_attribute = &m_attribute;
 	}
 }
 BoolLit::BoolLit(const BoolLit & other) {
	if (m_primitive != NULL) {
	  m_primitive = other.m_primitive->clone();
	}
 }
 BoolLit &BoolLit::operator=(const BoolLit & other) { BoolLit tmp(other); swap(tmp); return *this; }
 void BoolLit::swap(BoolLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 BoolLit::~BoolLit() {
 	if (m_primitive != NULL) {
	  delete(m_primitive);
 	}
 }
 void BoolLit::visit_children( Visitor* v ) {
 	if (m_primitive != NULL) {
	  m_primitive->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void BoolLit::accept(Visitor *v) { v->visitBoolLit(this); }
 BoolLit *BoolLit::clone() const { return new BoolLit(*this); }
 
 
/********* RatLit ************/
 RatLit::RatLit(Primitive *p1, Primitive *p2)  {
	m_primitive_1 = p1;
	m_primitive_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	if (m_primitive_1 != NULL) {
	  m_primitive_1->m_parent_attribute = &m_attribute;
 	}
	if (m_primitive_2 != NULL) {
	  m_primitive_2->m_parent_attribute = &m_attribute;
 	}
 }
 RatLit::RatLit(const RatLit & other) {
	if (m_primitive_1 != NULL) {
	  m_primitive_1 = other.m_primitive_1->clone();
	}
	if (m_primitive_2 != NULL) {
	  m_primitive_2 = other.m_primitive_2->clone();
	}
 }
 RatLit &RatLit::operator=(const RatLit & other) { RatLit tmp(other); swap(tmp); return *this; }
 void RatLit::swap(RatLit & other) {
	std::swap(m_primitive_1, other.m_primitive_1);
	std::swap(m_primitive_2, other.m_primitive_2);
 }
 RatLit::~RatLit() {
 	if (m_primitive_1 != NULL) {
	  delete(m_primitive_1);
 	}
	if (m_primitive_2 != NULL) {
	  delete(m_primitive_2);
 	}
 }
 void RatLit::visit_children( Visitor* v ) {
 	if (m_primitive_1 != NULL) {
	  m_primitive_1->accept( v );
 	} else {
		v->visitNullPointer();
	}
	if (m_primitive_2 != NULL) {
	  m_primitive_2->accept( v );
 	} else {
		v->visitNullPointer();
	}
 }
 void RatLit::accept(Visitor *v) { v->visitRatLit(this); }
 RatLit *RatLit::clone() const { return new RatLit(*this); }
 
 

