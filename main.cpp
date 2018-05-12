#include "token.h"
#include <FlexLexer.h>
#include <cstdlib>
#include <iostream>

int main() {
    FlexLexer *lexer = new yyFlexLexer();
    auto codes = std::string();
    auto tokens = std::string();
    int token = INVALID;
    int lastToken = INVALID;
    int no = lexer->lineno();
    while (true) {
        token = lexer->yylex();
        if (token == INVALID) {
            break;
        }
        if (lastToken == L_NEWLINE && token == L_EOF) {
            break;
        }
        if (token == L_NEWLINE || token == L_EOF) {
            std::cout << "#" << no << ": " << codes << std::endl;
            std::cout << "    " << tokens << std::endl;
            codes.clear();
            tokens.clear();
            if (token == L_EOF) {
                break;
            }
            lastToken = token;
            no = lexer->lineno();
            continue;
        }
        codes.append(lexer->YYText());
        codes.append(" ");
        tokens.append(TokenString(TOKEN(token)));
        tokens.append(" ");
    }
    if (token == INVALID) {
        std::cout << "Invalid token on line: " << lexer->lineno() << " "
                  << lexer->YYText() << std::endl;
    }
}
