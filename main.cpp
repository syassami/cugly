#include "ast.hpp"
#include "parser.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include <assert.h>

extern int yydebug; // set this to 1 if you want yyparse to dump a trace
extern int yyparse(); // this actually the parser which then calls the scanner

Program_ptr ast; /* make sure to set this to the final syntax tree in parser.ypp*/

// I didn't make you write a header for typecheck and codegen so we need to declare
// these two functions so we can call them
void dopass_typecheck(Program_ptr ast, SymTab *st); // this is defined in typecheck.cpp
void dopass_codegen(Program_ptr ast, SymTab *st); // this is defined in codegen.cpp


int main(void) {

	SymTab st; //symbol table

	// set this to 1 if you would like to print a trace 
	// of the entire parsing process (it prints to stdout)
        yydebug = 0; 

	// after parsing, the global "ast" should be set to the
	// syntax tree that we have built up during the parse
        yyparse();  

	if (ast) {
		dopass_typecheck( ast, &st );
		dopass_codegen( ast, &st );
	}
	return 0;
}

