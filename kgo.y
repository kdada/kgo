%skeleton "lalr1.cc"
%define parser_class_name {Parser}

%code requires{
#include "token.hpp"
#include "ast.hpp"

namespace yy {
class Scanner {
  public:
    virtual kgo::TOKEN next(void *token) = 0;
    virtual void set(kgo::Node *root) = 0;
    virtual void error(const std::string& msg) = 0;
};
}
}

%parse-param { Scanner *scanner }

%{
#undef yylex
#define yylex scanner->next
%}



%union {
kgo::Node *node;
kgo::Token *token;
}

%token <token> Z_EOF 0
%token <token> Z_INVALID 1

%token <token> K_BOOL 101
%token <token> K_CHAR 102
%token <token> K_BYTE 103
%token <token> K_SHORT 104
%token <token> K_USHORT 105
%token <token> K_INT 106
%token <token> K_UINT 107
%token <token> K_LONG 108
%token <token> K_ULONG 109
%token <token> K_FLOAT 110
%token <token> K_DOUBLE 111
%token <token> K_VAR 112
%token <token> K_CONST 113
%token <token> K_IF 114
%token <token> K_ELSE 115
%token <token> K_SWITCH 116
%token <token> K_CASE 117
%token <token> K_CONTINUE 118
%token <token> K_FALLTHROUGH 119
%token <token> K_DEFAULT 120
%token <token> K_FOR 121
%token <token> K_BREAK 122
%token <token> K_ENUM 123
%token <token> K_STRUCT 124
%token <token> K_FUNC 125
%token <token> K_PACKAGE 126
%token <token> K_IMPORT 127
%token <token> K_RETURN 128
%token <token> K_IOTA 129

%token <token> L_BOOL 201
%token <token> L_INT 202
%token <token> L_FLOAT 203
%token <token> L_CHAR 204
%token <token> L_STRING 205
%token <token> L_NEWLINE 206
%token <token> L_DOT 207
%token <token> L_SPACE 208
%token <token> L_COMMENT 209

%token <token> O_ASSIGNMENT 301
%token <token> O_ASSIGNMENT_PLUS 302
%token <token> O_ASSIGNMENT_MINUS 303
%token <token> O_ASSIGNMENT_MULTIPLY 304
%token <token> O_ASSIGNMENT_DIVIDE 305
%token <token> O_ASSIGNMENT_MOD 306
%token <token> O_LOGIC_AND 307
%token <token> O_LOGIC_OR 308
%token <token> O_LOGIC_NOT 309
%token <token> O_LOGIC_EQUAL 310
%token <token> O_LOGIC_GT 311
%token <token> O_LOGIC_GE 312
%token <token> O_LOGIC_LT 313
%token <token> O_LOGIC_LE 314
%token <token> O_LOGIC_NE 315
%token <token> O_ARITHMETIC_PLUS 316
%token <token> O_ARITHMETIC_MINUS 317
%token <token> O_ARITHMETIC_MULTIPLY 318
%token <token> O_ARITHMETIC_DIVIDE 319
%token <token> O_ARITHMETIC_MOD 320
%token <token> O_BIT_AND 321
%token <token> O_BIT_OR 322
%token <token> O_BIT_NOT 323
%token <token> O_BIT_XOR 324
%token <token> O_BIT_LEFT 325
%token <token> O_BIT_RIGHT 326

%token <token> C_PARENTHESIS_LEFT 401
%token <token> C_PARENTHESIS_RIGHT 402
%token <token> C_BRACKET_LEFT 403
%token <token> C_BRACKET_RIGHT 404
%token <token> C_BRACE_LEFT 405
%token <token> C_BRACE_RIGHT 406
%token <token> C_COMMA 407
%token <token> C_SEMICOLON 408
%token <token> C_COLON 409

%token <token> T_ID 501

%type <node> exprs expr factor term

%%
exprs: expr L_NEWLINE                                        {scanner->set($$);}
	 ;

expr: factor
	| expr O_ARITHMETIC_PLUS factor                          {$$ = new kgo::Node($2,$1,$3);}
	| expr O_ARITHMETIC_MINUS factor                         {$$ = new kgo::Node($2,$1,$3);}
	;

factor: term   
	  | factor O_ARITHMETIC_MULTIPLY term                    {$$ = new kgo::Node($2,$1,$3);}
	  | factor O_ARITHMETIC_DIVIDE term                      {$$ = new kgo::Node($2,$1,$3);}
	  | factor O_ARITHMETIC_MOD term                         {$$ = new kgo::Node($2,$1,$3);}
	  ;

term: L_INT	                                                 {$$ = new kgo::Node($1);}
	| L_FLOAT                                                {$$ = new kgo::Node($1);}
	| C_PARENTHESIS_LEFT expr C_PARENTHESIS_RIGHT            {$$ = new kgo::Node($1,$2,nullptr);}
	;

%%

void yy::Parser::error(const std::string& msg) {
	scanner->error(msg);
}
