#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP
#include <stdlib.h>
//SymScope is declared in SymTab.cpp
class SymScope;

enum Basetype
{
	bt_undef,

	bt_integer,
	bt_boolean,
	bt_complex,
	bt_procedure,
	bt_intarray,
	bt_rational,
	bt_auto
};


class Attribute
{
  public:
  Basetype m_basetype; //type of the subtree
  int m_place; //register where this value is stored
  SymScope* m_scope; //the scope of the current symbol
  int lineno; //line number on which that ast node resides

  Attribute() { 
	m_basetype = bt_undef;
	lineno = 0;
	m_scope = NULL;
	int m_place = -1; //should never actually be negative
  }
};

#endif //ATTRIBUTE_HPP

