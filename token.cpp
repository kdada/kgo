#include "token.h"

char const *TokenString(enum TOKEN token) {
    switch (token) {
    case INVALID:
        return "INVALID";

    case K_BOOL:
        return "K_BOOL";

    case K_CHAR:
        return "K_CHAR";

    case K_BYTE:
        return "K_BYTE";

    case K_SHORT:
        return "K_SHORT";

    case K_USHORT:
        return "K_USHORT";

    case K_INT:
        return "K_INT";

    case K_UINT:
        return "K_UINT";

    case K_LONG:
        return "K_LONG";

    case K_ULONG:
        return "K_ULONG";

    case K_FLOAT:
        return "K_FLOAT";

    case K_DOUBLE:
        return "K_DOUBLE";

    case K_VAR:
        return "K_VAR";

    case K_CONST:
        return "K_CONST";

    case K_IF:
        return "K_IF";

    case K_ELSE:
        return "K_ELSE";

    case K_SWITCH:
        return "K_SWITCH";

    case K_CASE:
        return "K_CASE";

    case K_CONTINUE:
        return "K_CONTINUE";

    case K_FALLTHROUGH:
        return "K_FALLTHROUGH";

    case K_DEFAULT:
        return "K_DEFAULT";

    case K_FOR:
        return "K_FOR";

    case K_BREAK:
        return "K_BREAK";

    case K_ENUM:
        return "K_ENUM";

    case K_STRUCT:
        return "K_STRUCT";

    case K_FUNC:
        return "K_FUNC";

    case K_PACKAGE:
        return "K_PACKAGE";

    case K_IMPORT:
        return "K_IMPORT";

    case K_RETURN:
        return "K_RETURN";

    case L_BOOL:
        return "L_BOOL";

    case L_INT:
        return "L_INT";

    case L_FLOAT:
        return "L_FLOAT";

    case L_CHAR:
        return "L_CHAR";

    case L_STRING:
        return "L_STRING";

    case L_NEWLINE:
        return "L_NEWLINE";

    case L_EOF:
        return "L_EOF";

    case O_ASSIGNMENT:
        return "O_ASSIGNMENT";

    case O_ASSIGNMENT_PLUS:
        return "O_ASSIGNMENT_PLUS";

    case O_ASSIGNMENT_MINUS:
        return "O_ASSIGNMENT_MINUS";

    case O_ASSIGNMENT_MULTIPLY:
        return "O_ASSIGNMENT_MULTIPLY";

    case O_ASSIGNMENT_DIVIDE:
        return "O_ASSIGNMENT_DIVIDE";

    case O_ASSIGNMENT_MOD:
        return "O_ASSIGNMENT_MOD";

    case O_LOGIC_AND:
        return "O_LOGIC_AND";

    case O_LOGIC_OR:
        return "O_LOGIC_OR";

    case O_LOGIC_NOT:
        return "O_LOGIC_NOT";

    case O_LOGIC_EQUAL:
        return "O_LOGIC_EQUAL";

    case O_LOGIC_GT:
        return "O_LOGIC_GT";

    case O_LOGIC_GE:
        return "O_LOGIC_GE";

    case O_LOGIC_LT:
        return "O_LOGIC_LT";

    case O_LOGIC_LE:
        return "O_LOGIC_LE";

    case O_LOGIC_NE:
        return "O_LOGIC_NE";

    case O_ARITHMETIC_PLUS:
        return "O_ARITHMETIC_PLUS";

    case O_ARITHMETIC_MINUS:
        return "O_ARITHMETIC_MINUS";

    case O_ARITHMETIC_MULTIPLY:
        return "O_ARITHMETIC_MULTIPLY";

    case O_ARITHMETIC_DIVIDE:
        return "O_ARITHMETIC_DIVIDE";

    case O_ARITHMETIC_MOD:
        return "O_ARITHMETIC_MOD";

    case O_BIT_AND:
        return "O_BIT_AND";

    case O_BIT_OR:
        return "O_BIT_OR";

    case O_BIT_NOT:
        return "O_BIT_NOT";

    case O_BIT_XOR:
        return "O_BIT_XOR";

    case O_BIT_LEFT:
        return "O_BIT_LEFT";

    case O_BIT_RIGHT:
        return "O_BIT_RIGHT";

    case C_PARENTHESIS_LEFT:
        return "C_PARENTHESIS_LEFT";

    case C_PARENTHESIS_RIGHT:
        return "C_PARENTHESIS_RIGHT";

    case C_BRACKET_LEFT:
        return "C_BRACKET_LEFT";

    case C_BRACKET_RIGHT:
        return "C_BRACKET_RIGHT";

    case C_BRACE_LEFT:
        return "C_BRACE_LEFT";

    case C_BRACE_RIGHT:
        return "C_BRACE_RIGHT";

    case C_COMMA:
        return "C_COMMA";

    case C_SEMICOLON:
        return "C_SEMICOLON";

    case T_ID:
        return "T_ID";
    }
}
