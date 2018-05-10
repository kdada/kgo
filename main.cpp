#include "token.h"
#include <FlexLexer.h>
#include <cstdlib>
#include <iostream>

int main() {
    FlexLexer *lexer = new yyFlexLexer();
    auto line = 1;
    auto codes = std::string();
    auto tokens = std::string();
    int token = INVALID;
    int lastToken = INVALID;
    while (true) {
        token = lexer->yylex();
        if (lastToken == L_NEWLINE && token == L_EOF) {
            break;
        }
        if (token == L_NEWLINE || token == L_EOF) {
            std::cout << "#" << line << ": " << codes << std::endl;
            std::cout << "    " << tokens << std::endl;
            codes.clear();
            tokens.clear();
            line++;
            if (token == L_EOF) {
                break;
            }
            lastToken = token;
            continue;
        }
        codes.append(lexer->YYText());
        codes.append(" ");
        tokens.append(TokenString(TOKEN(token)));
        tokens.append(" ");
    }
    if (token == INVALID) {
        std::cout << "Invalid token on line: " << line << " " << lexer->YYText()
                  << std::endl;
    }
}
