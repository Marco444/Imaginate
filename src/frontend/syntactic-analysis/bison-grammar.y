%{

#include "bison-actions.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {
	// No-terminales (backend).
	/*
	Program program;
	Expression expression;
	Factor factor;
	Constant constant;
	...
	*/
  int variable;

// No-terminales (frontend).
	int program;
	int expression;
	int factor;
	int constant;
	int assignment;

// Terminales.
	token token;
	int integer;
}

// IDs y tipos de los tokens terminales generados desde Flex.
%token <token> ADD
%token <token> START 
%token <token> SUB
%token <token> MUL
%token <token> DIV

%token <token> OPEN_PARENTHESIS
%token <token> CLOSE_PARENTHESIS

%token <integer> INTEGER

%token <variable> VARIABLE
%token <token> EQUALS
%token <token> VAL 

// Tipos de dato para los no-terminales generados desde Bison.
%type <program> program
%type <expression> expression
%type <factor> factor
%type <constant> constant
%type <assignment> assignment 

// Reglas de asociatividad y precedencia (de menor a mayor).
%left ADD SUB
%left MUL DIV

// El símbolo inicial de la gramatica.
%start program

%%

program: expression																						{ $$ = ProgramGrammarAction($1); }
			 | assignment                                            { $$ = ProgramGrammarAction($1); }
			 ; 

expression: expression[left] ADD expression[right]						{ $$ = AdditionExpressionGrammarAction($left, $right); }
					| expression[left] SUB expression[right]						{ $$ = SubtractionExpressionGrammarAction($left, $right); }
					| expression[left] MUL expression[right]						{ $$ = MultiplicationExpressionGrammarAction($left, $right); }
					| expression[left] DIV expression[right]						{ $$ = DivisionExpressionGrammarAction($left, $right); }
					| factor																						{ $$ = FactorExpressionGrammarAction($1); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS { $$ = ExpressionFactorGrammarAction($2); }
			| constant { $$ = ConstantFactorGrammarAction($1); }
			;

assignment: VAL VARIABLE EQUALS INTEGER { $$ = VariableAssignmentGrammarAction($2, $4); };

constant: INTEGER													{ $$ = IntegerConstantGrammarAction($1); }
				;

%%
