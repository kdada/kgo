#include "token.h"
#include <FlexLexer.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>

bool scan(char *path) {
    std::ifstream file(path);
    auto lexer = std::make_unique<yyFlexLexer>(&file);
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
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            i++;
        }
        std::cout << "Parse " << argv[i] << std::endl << std::endl;
        if (!scan(argv[i])) {
            return 1;
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}
