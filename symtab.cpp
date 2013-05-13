#include <algorithm>
#include "symtab.hpp"
#include <assert.h>
#include <stdio.h>

/****** SymName Implemenation **************************************/

SymName::SymName(const char* x)
{
	m_spelling = x;
	m_parent_attribute = NULL;
}

SymName::SymName(const SymName & other)
{
	m_spelling = strdup(other.m_spelling);
	m_parent_attribute = other.m_parent_attribute;
}

SymName& SymName::operator=(const SymName & other)
{
	delete m_spelling;
	SymName tmp(other);
	swap(tmp);
	return *this;
}

void SymName::swap(SymName & other)
{
	std::swap(m_spelling, other.m_spelling);
}

SymName::~SymName()
{
	delete( m_spelling );
}

void SymName::accept(Visitor *v)
{ 
	v->visitSymName(this); 
}

SymName* SymName::clone() const
{
	return new SymName(*this);
}

const char* SymName::spelling()
{
	return m_spelling;
}

Symbol* SymName::symbol()
{
	return m_symbol;
}

void SymName::set_symbol(Symbol* s)
{
	//you should not try to reset a symbol pointer
	//once it is set, that pointer is used all 
	//sorts of places - changes to it once it is
	//set can results in weird behavior
	assert( m_symbol == NULL );
	m_symbol = s;
}


/****** SymScope Def (used by SymTab) **************************************/

//comparison structure for strings
struct eqstr { 
	bool operator()(const char* s1, const char* s2) const 
  	{ return strcmp(s1, s2) == 0; }
};


class SymScope
{
  private:

  SymScope* m_parent;
  list<SymScope*> m_child;
  typedef hash_map<const char*, Symbol*, hash<const char*>, eqstr> ScopeTableType;
  ScopeTableType m_scopetable;
  bool as_param;
  int m_localsize; 
  int m_paramsize;
  SymScope* parent();
  void add_child(SymScope* c);
  SymScope(SymScope * parent);
  bool is_dup_string(const char* name); //used for error check

  void dump( FILE* f, int nest_level );
  void set_param_mode() { as_param = true; }
  void set_local_mode() { as_param = false; }
  SymScope* open_scope();
  SymScope* close_scope();
  bool exist( const char* name );
  Symbol* insert( const char* name, Symbol * s ); 
  Symbol* lookup( const char * name ); 


  public:

  SymScope();
  ~SymScope();

  friend class SymTab; //symtab is a wrapper class

};


/****** SymTab Implementation **************************************/

SymTab::SymTab()
{
	m_head = new SymScope;
	m_cur_scope = m_head;
}

SymTab::~SymTab()
{
	delete m_head;
}

bool SymTab::is_dup_string(const char* name)
{
	return m_head->is_dup_string(name);
}

void SymTab::open_scope()
{
	m_cur_scope = m_cur_scope->open_scope();
	assert( m_cur_scope != NULL );
}

void SymTab::close_scope()
{
	//check to make sure we don't pop more than we push
	assert( m_cur_scope != m_head ); 
	assert( m_cur_scope != NULL );

	m_cur_scope = m_cur_scope->close_scope();
}

void SymTab::set_param_mode() { m_cur_scope->set_param_mode(); }
void SymTab::set_local_mode() { m_cur_scope->set_local_mode(); }

SymScope* SymTab::get_scope()
{
	//check that we actually have a scope before we return it
	assert( m_cur_scope != NULL ); 
	return m_cur_scope;
}

// Returns the lexical level of the symbol
// Procedure symbol levels are increased by one to give the
// expected results, even though the procedure name appears one
// level below.
int SymTab::get_lexical_level(Symbol *s)
{
  int level = lexical_distance(m_head, s->get_scope());
  if (s->m_basetype == bt_procedure)
    return level + 1;
  return level;
}

bool SymTab::exist( const char* name )
{
	assert( name != NULL );
	return m_cur_scope->exist( name );
}

bool SymTab::insert( const char* name, Symbol * s )
{
	assert( name != NULL );
	assert( s != NULL );
	// the assert below fails, it is because you tried to insert
	// a pointer to a string that is already in the SymTab.  You 
	// can have duplicate names, but each needs to reside it it's
	// own chunk of memory (see example)
	assert( is_dup_string(name) ); 
	Symbol* r = m_cur_scope->insert( name, s );
	if ( r == NULL ) return true;
	else return false;
}

bool SymTab::insert_in_parent_scope( const char* name, Symbol * s )
{
	assert( name != NULL );
	assert( s != NULL );
	// the assert below fails, it is because you tried to insert
	// a pointer to a string that is already in the SymTab.  You 
	// can have duplicate names, but each needs to reside it it's
	// own chunk of memory (see example)
	assert( is_dup_string(name) ); 
	// make sure there is an actual parent scope
	assert( m_cur_scope->m_parent != NULL );	
	Symbol* r = m_cur_scope->m_parent->insert( name, s );
	if ( r == NULL ) return true;
	else return false;
}

Symbol* SymTab::lookup( const char * name )
{
	assert( name != NULL );
	return m_cur_scope->lookup( name );
}

Symbol* SymTab::lookup( SymScope* targetscope, const char * name )
{
	assert( name != NULL );
	assert( targetscope != NULL );
	return targetscope->lookup( name );
}

int SymTab::scopesize( SymScope* targetscope )
{
	return targetscope->m_localsize;
}

int SymTab::lexical_distance( SymScope* higher_scope, SymScope* deeper_scope )
{
	assert(deeper_scope != NULL);
	assert(higher_scope != NULL);
	if( higher_scope == deeper_scope ) return 0;
	return lexical_distance( higher_scope, deeper_scope->m_parent ) + 1;
}

void SymTab::dump( FILE* f )
{
	m_head->dump(f, 0);
}

/****** SymScope Implementation **************************************/

SymScope::SymScope() 
{
	m_parent = NULL; 
	m_localsize = 0;
	m_paramsize = 0;
	as_param = false;
}

SymScope::SymScope(SymScope * parent) 
{
	m_parent = parent;
	m_localsize = 0;
	m_paramsize = 0;
	if (parent!=NULL) {
		parent->add_child(this); 
	}
}

SymScope::~SymScope()
{
	//delete the keys, but not the symbols (symbols are linked elsewhere)
	ScopeTableType::iterator si, this_si;

	si = m_scopetable.begin();
	while ( si!=m_scopetable.end() )
	{
		char* oldkey = (char*)si->first;
		this_si = si;
		++si;

		m_scopetable.erase( this_si );
		free( oldkey );
	}

	//now delete all the children
	list<SymScope*>::iterator li;
	for( li=m_child.begin(); li!=m_child.end(); ++li )
	{
		delete *li;
	}
}

void SymScope::dump(FILE* f, int nest_level)
{
	//recursively prints out the symbol table
	//from the head down through all the childrens

	ScopeTableType::iterator si;

	//indent appropriately
	fprintf(f,"# ");
	for( int i=0; i<nest_level; i++ ) { fprintf(f,"\t"); }
	fprintf(f," +-- Symbol Scope (%d bytes at %x)---\n", m_localsize,
		this);

	for( si = m_scopetable.begin(); si != m_scopetable.end(); ++si )
	{
		//indent appropriately
		fprintf(f,"# ");
		for( int i=0; i<nest_level; i++ ) { fprintf(f,"\t"); }
		fprintf( f, "| %s (offset=%d,scope=%x)\n", si->first, si->second->m_offset, si->second->m_symscope );
	}
	fprintf(f,"# ");
	for( int i=0; i<nest_level; i++ ) { fprintf(f,"\t"); }
	fprintf(f,"+-------------\n#\n");

	//now print all the children
	list<SymScope*>::iterator li;
	for( li=m_child.begin(); li!=m_child.end(); ++li )
	{
		(*li)->dump(f, nest_level+1);
	}
}

bool SymScope::is_dup_string(const char* name)
{
	ScopeTableType::iterator si;

	si = m_scopetable.find( name );
	if ( si != m_scopetable.end() ) {
		//check if the pointers match
		if ( si->first == name ) return false;
	}

	list<SymScope*>::iterator li;
	for( li=m_child.begin(); li!=m_child.end(); ++li )
	{
		bool r = (*li)->is_dup_string(name);
		if ( r==false ) return false;
	}

	//if it gets this far, there is no duplicate
	return true;
}

void SymScope::add_child(SymScope* c) 
{
	m_child.push_back(c);
}


SymScope* SymScope::open_scope() 
{
	return new SymScope(this);
}

SymScope* SymScope::close_scope()
{
	return m_parent;
}

bool SymScope::exist( const char* name )
{
	Symbol* s;
	s = lookup(name);
	// return true if name exists
	if ( s!=NULL ) return true;
	else return false;
}

Symbol* SymScope::insert( const char* name, Symbol * s )
{
	pair<ScopeTableType::iterator,bool> iret;
	typedef pair<const char*,Symbol*> hpair;
	iret = m_scopetable.insert( hpair(name,s) );
	if( iret.second == true ) {
	  //insert was successfull
	  //update the offset and size
	  if (as_param) {
	    // Inserts at positive values
	    s->m_offset = m_paramsize;
	    m_paramsize += s->get_size();
	  }
	  else {
	    // Inserts at negative values
	    m_localsize += s->get_size();
	    s->m_offset = -m_localsize;
	  }
	  //set the scope
	  s->m_symscope = this;
	  return NULL;
	} else {
		//cannot insert, there was a duplicate entry
		//return a pointer to the conflicting symbol
		return iret.first->second;
	}	
}
 
Symbol* SymScope::lookup( const char * name )
{
	//first check the current table;
	ScopeTableType::const_iterator i;
	i = m_scopetable.find( name );
	if ( i != m_scopetable.end() ) {
		return i->second;
	}

	//failing that, check all the parents;
	if ( m_parent != NULL ) {
		return m_parent->lookup( name );
	} else {
		//if this has no parents, then it cannot be found
		return NULL;
	}
}


