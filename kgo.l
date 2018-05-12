%{
#include "token.h"
%}

%option noyywrap c++

%%
[ \t]                    ;
bool                     return K_BOOL;
char                     return K_CHAR;
byte                     return K_BYTE;
short                    return K_SHORT;
ushort                   return K_USHORT;
int                      return K_INT;
uint                     return K_UINT;
long                     return K_LONG;
ulong                    return K_ULONG;
float                    return K_FLOAT;
double                   return K_DOUBLE;
var                      return K_VAR;
const                    return K_CONST;
if                       return K_IF;
else                     return K_ELSE;
switch                   return K_SWITCH;
case                     return K_CASE;
continue                 return K_CONTINUE;
fallthrough              return K_FALLTHROUGH;
default                  return K_DEFAULT;
for                      return K_FOR;
break                    return K_BREAK;
enum                     return K_ENUM;
struct                   return K_STRUCT;
func                     return K_FUNC;
package                  return K_PACKAGE;
import                   return K_IMPORT;
return                   return K_RETURN;
iota                     return K_IOTA;
type                     return K_IOTA;

\'(\\.|[^'\\])\'         return L_CHAR;
\"(\\.|[^"\\])*\"        return L_STRING;
`[^`]*`                  for(int i=0;i<yyleng;++i)if(yytext[i]=='\n')yylineno++;return L_STRING;
(0|[1-9][0-9]*)\.[0-9]+  return L_FLOAT;
(0|[1-9][0-9]*)          return L_INT;
(true|false)             return L_BOOL;
\n                       yylineno++; return L_NEWLINE;
<<EOF>>                  return L_EOF;
\.                       return L_DOT;

=                        return O_ASSIGNMENT;
\+=                      return O_ASSIGNMENT_PLUS;
\-=                      return O_ASSIGNMENT_MINUS;
\*=                      return O_ASSIGNMENT_MULTIPLY;
\/=                      return O_ASSIGNMENT_DIVIDE;
%=                       return O_ASSIGNMENT_MOD;
&&                       return O_LOGIC_AND;
\|\|                     return O_LOGIC_OR;
!                        return O_LOGIC_NOT;
==                       return O_LOGIC_EQUAL;
>                        return O_LOGIC_GT;
>=                       return O_LOGIC_GE;
\<                       return O_LOGIC_LT;
\<=                      return O_LOGIC_LE;
!=                       return O_LOGIC_NE;
\+                       return O_ARITHMETIC_PLUS;
-                        return O_ARITHMETIC_MINUS;
\*                       return O_ARITHMETIC_MULTIPLY;
\/                       return O_ARITHMETIC_DIVIDE;
%                        return O_ARITHMETIC_MOD;
&                        return O_BIT_AND;
\|                       return O_BIT_OR;
~                        return O_BIT_NOT;
\^                       return O_BIT_XOR;
\<\<                     return O_BIT_LEFT;
>>                       return O_BIT_RIGHT;

\(                       return C_PARENTHESIS_LEFT;
\)                       return C_PARENTHESIS_RIGHT;
\[                       return C_BRACKET_LEFT;
\]                       return C_BRACKET_RIGHT;
\{                       return C_BRACE_LEFT;
\}                       return C_BRACE_RIGHT;
,                        return C_COMMA;
;                        return C_SEMICOLON;
:                        return C_COLON;

[a-zA-Z][a-zA-Z0-9]*(_[a-zA-Z0-9]+)*     return T_ID;

.                        return INVALID;
%%
