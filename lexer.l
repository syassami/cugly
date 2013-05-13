%option yylineno
%pointer

%{
#include <stdlib.h>
#include <string.h>
#include "ast.hpp"
#include "parser.hpp"
#include "primitive.hpp"
#include <iostream>

char* p;
void yyerror(const char *);
%}


%x COMMENT

%%

"--%"                 { BEGIN(COMMENT); }
<COMMENT>\n 		  { ++yylineno; }
<COMMENT>"%--"        { BEGIN(INITIAL); }
<COMMENT><<EOF>>      { yyerror("EOF found in comment"); exit(1); }
<COMMENT>.
"boolean"             {
						p=(char *)calloc(strlen(yytext)+1,sizeof(char));
					   	strcpy(p,yytext);
					   	yylval.u_base_charptr=p;
						return TYPE;
					  }
"integer"             {
						p=(char *)calloc(strlen(yytext)+1,sizeof(char));
					   	strcpy(p,yytext);
					   	yylval.u_base_charptr=p;
						return TYPE;
					  }
"rational"            {
						p=(char *)calloc(strlen(yytext)+1,sizeof(char));
					   	strcpy(p,yytext);
					   	yylval.u_base_charptr=p;
						return TYPE;
					  }
"auto"                {
						p=(char *)calloc(strlen(yytext)+1,sizeof(char));
					   	strcpy(p,yytext);
					   	yylval.u_base_charptr=p;
						return TYPE;
					  }
"if"                  {/*printf("if ");*/ return IF;}
"else"                {/*printf("else ");*/ return ELSE;}
"while"               {/*printf("while ");*/ return WHILE;}
"var"                 {/*printf("var ");*/ return VAR;}
"function"            {/*printf("function ");*/ return FUNCTION;}
"return"              {/*printf("return ");*/ return RETURN;}
"yield"               {/*printf("yield ");*/ return YIELD;}

"+"                   {/*printf("+ ");*/ return PLUS; }
"-"                   {/*printf("- ");*/ return MINUS; }
"*"                   {/*printf("* ");*/ return TIMES; }
"/."                  {/*printf("/. ");*/ return DIV; }  
":="                  {/*printf(":= ");*/ return AS_OP; }         
"=="                  {/*printf("== ");*/ return EQ_OP; }    
">"                   {/*printf("> ");*/ return GT_OP; }    
">="                  {/*printf(">= ");*/ return GE_OP; }    
"<"                   {/*printf("< ");*/ return LT_OP; }    
"<="                  {/*printf("<= ");*/ return LE_OP; }    
"!="                  {/*printf("!= ");*/ return NE_OP; }    
"&&"                  {/*printf("&& ");*/ return AND_OP; }    
"||"                  {/*printf("|| ");*/ return OR_OP; }
"!"    				  {/*printf("! ");*/ return NOT_OP; }

"true"				  {yylval.u_base_int=1; return TRUE_NT;}
"false"      		  {yylval.u_base_int=0; return FALSE_NT;}
[0]					  {yylval.u_base_int=0; return INT;}
[1-9][0-9]*   		  {yylval.u_base_int=atoi(yytext); return INT;}
[0][0-9A-F]+[x]       {yylval.u_base_int=strtol(yytext,NULL,16); return INT;}
[0-1]+[b]             {yylval.u_base_int=strtol(yytext,NULL,2); return INT;}
[0-9]*[/][1-9][0-9]*  { 
						string pre_rational = yytext;
						int before = atoi(pre_rational.substr(0,pre_rational.find('/')).c_str());
						int after = atoi(pre_rational.substr(pre_rational.find('/')+1,pre_rational.length()).c_str());
 						Primitive* bp = new Primitive(before);
 						Primitive* ap = new Primitive(after);
 						RatLit *rl = new RatLit(bp, ap);
 						yylval.u_expr = rl;
 						return RATIONAL;
					  }
[a-zA-Z][a-zA-Z0-9_]* {
					   p=(char *)calloc(strlen(yytext)+1,sizeof(char));
					   strcpy(p,yytext);
					   yylval.u_base_charptr=p;
					   return IDENTIFIER;
					  }
;                     { /* printf("semicolon\n"); */  return SEMICOLON; }                 
\:                    { /* printf("colon"); */  return COLON; }
\[                    { /* printf("openbracket"); */  return OPENBRACKET; }
\]                    { /* printf("closebracket"); */  return CLOSEBRACKET; }
\{                    { /* printf("opencurly"); */   return OPENCURLY; }
\}                    { /* printf("closecurly"); */  return CLOSECURLY; }
\,                    { /* printf("comma"); */  return COMMA; }
\(                    { /* printf("openparen"); */  return OPENPAREN; }
\)                    { /* printf("closeparen"); */  return CLOSEPAREN; }
[ \t\n]               ; /* skip whitespace */

.                     yyerror((char *) "invalid character");
%%

int yywrap(void) {
	return 1;
}
