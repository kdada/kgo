%{
#include "token.hpp"
%}

%option c++ noyywrap nodefault

%x COMMENT
%%
bool                     return kgo::K_BOOL;
char                     return kgo::K_CHAR;
byte                     return kgo::K_BYTE;
short                    return kgo::K_SHORT;
ushort                   return kgo::K_USHORT;
int                      return kgo::K_INT;
uint                     return kgo::K_UINT;
long                     return kgo::K_LONG;
ulong                    return kgo::K_ULONG;
float                    return kgo::K_FLOAT;
double                   return kgo::K_DOUBLE;
var                      return kgo::K_VAR;
const                    return kgo::K_CONST;
if                       return kgo::K_IF;
else                     return kgo::K_ELSE;
switch                   return kgo::K_SWITCH;
case                     return kgo::K_CASE;
continue                 return kgo::K_CONTINUE;
fallthrough              return kgo::K_FALLTHROUGH;
default                  return kgo::K_DEFAULT;
for                      return kgo::K_FOR;
break                    return kgo::K_BREAK;
enum                     return kgo::K_ENUM;
struct                   return kgo::K_STRUCT;
func                     return kgo::K_FUNC;
package                  return kgo::K_PACKAGE;
import                   return kgo::K_IMPORT;
return                   return kgo::K_RETURN;
iota                     return kgo::K_IOTA;
type                     return kgo::K_IOTA;

\'(\\.|[^'\\])\'         return kgo::L_CHAR;
\"(\\.|[^"\\])*\"        return kgo::L_STRING;
`[^`]*`                  for(int i=0;i<yyleng;++i)if(yytext[i]=='\n')yylineno++;return kgo::L_STRING;
(0|[1-9][0-9]*)\.[0-9]+  return kgo::L_FLOAT;
(0|[1-9][0-9]*)          return kgo::L_INT;
(true|false)             return kgo::L_BOOL;
\n                       yylineno++;return kgo::L_NEWLINE;
\.                       return kgo::L_DOT;
[ \t]+                   return kgo::L_SPACE;
\/\/[^\n]*               return kgo::L_COMMENT;
\/\*(\*[^\/]|[^\*])*\*?\*\/ for(int i=0;i<yyleng;++i)if(yytext[i]=='\n')yylineno++;return kgo::L_COMMENT;

=                        return kgo::O_ASSIGNMENT;
\+=                      return kgo::O_ASSIGNMENT_PLUS;
\-=                      return kgo::O_ASSIGNMENT_MINUS;
\*=                      return kgo::O_ASSIGNMENT_MULTIPLY;
\/=                      return kgo::O_ASSIGNMENT_DIVIDE;
%=                       return kgo::O_ASSIGNMENT_MOD;
&&                       return kgo::O_LOGIC_AND;
\|\|                     return kgo::O_LOGIC_OR;
!                        return kgo::O_LOGIC_NOT;
==                       return kgo::O_LOGIC_EQUAL;
>                        return kgo::O_LOGIC_GT;
>=                       return kgo::O_LOGIC_GE;
\<                       return kgo::O_LOGIC_LT;
\<=                      return kgo::O_LOGIC_LE;
!=                       return kgo::O_LOGIC_NE;
\+                       return kgo::O_ARITHMETIC_PLUS;
-                        return kgo::O_ARITHMETIC_MINUS;
\*                       return kgo::O_ARITHMETIC_MULTIPLY;
\/                       return kgo::O_ARITHMETIC_DIVIDE;
%                        return kgo::O_ARITHMETIC_MOD;
&                        return kgo::O_BIT_AND;
\|                       return kgo::O_BIT_OR;
~                        return kgo::O_BIT_NOT;
\^                       return kgo::O_BIT_XOR;
\<\<                     return kgo::O_BIT_LEFT;
>>                       return kgo::O_BIT_RIGHT;

\(                       return kgo::C_PARENTHESIS_LEFT;
\)                       return kgo::C_PARENTHESIS_RIGHT;
\[                       return kgo::C_BRACKET_LEFT;
\]                       return kgo::C_BRACKET_RIGHT;
\{                       return kgo::C_BRACE_LEFT;
\}                       return kgo::C_BRACE_RIGHT;
,                        return kgo::C_COMMA;
;                        return kgo::C_SEMICOLON;
:                        return kgo::C_COLON;

[a-zA-Z][a-zA-Z0-9]*(_[a-zA-Z0-9]+)*     return kgo::T_ID;

.                        return kgo::Z_INVALID;
<<EOF>>                  return kgo::Z_EOF;
%%
