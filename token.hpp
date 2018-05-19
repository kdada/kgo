#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

namespace kgo {

enum TOKEN {
    /*000*/ Z_EOF = 0,
    /*001*/ Z_INVALID,

    /*101*/ K_BOOL = 101,
    /*102*/ K_CHAR,
    /*103*/ K_BYTE,
    /*104*/ K_SHORT,
    /*105*/ K_USHORT,
    /*106*/ K_INT,
    /*107*/ K_UINT,
    /*108*/ K_LONG,
    /*109*/ K_ULONG,
    /*110*/ K_FLOAT,
    /*111*/ K_DOUBLE,
    /*112*/ K_VAR,
    /*113*/ K_CONST,
    /*114*/ K_IF,
    /*115*/ K_ELSE,
    /*116*/ K_SWITCH,
    /*117*/ K_CASE,
    /*118*/ K_CONTINUE,
    /*119*/ K_FALLTHROUGH,
    /*120*/ K_DEFAULT,
    /*121*/ K_FOR,
    /*122*/ K_BREAK,
    /*123*/ K_ENUM,
    /*124*/ K_STRUCT,
    /*125*/ K_FUNC,
    /*126*/ K_PACKAGE,
    /*127*/ K_IMPORT,
    /*128*/ K_RETURN,
    /*129*/ K_IOTA,

    /*201*/ L_BOOL = 201,
    /*202*/ L_INT,
    /*203*/ L_FLOAT,
    /*204*/ L_CHAR,
    /*205*/ L_STRING,
    /*206*/ L_NEWLINE,
    /*207*/ L_DOT,
    /*208*/ L_SPACE,
    /*209*/ L_COMMENT,

    /*301*/ O_ASSIGNMENT = 301,
    /*302*/ O_ASSIGNMENT_PLUS,
    /*303*/ O_ASSIGNMENT_MINUS,
    /*304*/ O_ASSIGNMENT_MULTIPLY,
    /*305*/ O_ASSIGNMENT_DIVIDE,
    /*306*/ O_ASSIGNMENT_MOD,
    /*307*/ O_LOGIC_AND,
    /*308*/ O_LOGIC_OR,
    /*309*/ O_LOGIC_NOT,
    /*310*/ O_LOGIC_EQUAL,
    /*311*/ O_LOGIC_GT,
    /*312*/ O_LOGIC_GE,
    /*313*/ O_LOGIC_LT,
    /*314*/ O_LOGIC_LE,
    /*315*/ O_LOGIC_NE,
    /*316*/ O_ARITHMETIC_PLUS,
    /*317*/ O_ARITHMETIC_MINUS,
    /*318*/ O_ARITHMETIC_MULTIPLY,
    /*319*/ O_ARITHMETIC_DIVIDE,
    /*320*/ O_ARITHMETIC_MOD,
    /*321*/ O_BIT_AND,
    /*322*/ O_BIT_OR,
    /*323*/ O_BIT_NOT,
    /*324*/ O_BIT_XOR,
    /*325*/ O_BIT_LEFT,
    /*326*/ O_BIT_RIGHT,

    /*401*/ C_PARENTHESIS_LEFT = 401,
    /*402*/ C_PARENTHESIS_RIGHT,
    /*403*/ C_BRACKET_LEFT,
    /*404*/ C_BRACKET_RIGHT,
    /*405*/ C_BRACE_LEFT,
    /*406*/ C_BRACE_RIGHT,
    /*407*/ C_COMMA,
    /*408*/ C_SEMICOLON,
    /*409*/ C_COLON,

    /*501*/ T_ID = 501,
};

class Token {
  public:
    TOKEN token;
    int line;
    int pos;
    std::string data;
    Token(TOKEN token, const char *data, int line, int pos);
};

char const *TokenString(enum TOKEN token);
}
#endif
