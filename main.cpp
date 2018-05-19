#include "parser.hpp"
#include "token.hpp"
#include <FlexLexer.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>

class Scanner : public yy::Scanner {
  public:
    Scanner(char *path);
    ~Scanner();

    virtual kgo::TOKEN next(void *token) override;
    virtual void set(kgo::Node *root) override;
    virtual void error(const std::string &msg) override;
    virtual bool scan();

  private:
    std::ifstream *file;
    FlexLexer *lexer;
    yy::Parser *parser;
    kgo::Node *root;
    int pos;
};

Scanner::Scanner(char *path) {
    this->file = new std::ifstream(path);
    this->lexer = new yyFlexLexer(this->file);
    this->parser = new yy::Parser(this);
    this->pos = 0;
};
Scanner::~Scanner() {
    delete this->parser;
    delete this->lexer;
    delete this->file;
};

kgo::TOKEN Scanner::next(void *pointer) {
    auto pos = this->pos;
    auto line = this->lexer->lineno();
    auto tk = (kgo::TOKEN)this->lexer->yylex();
    auto text = this->lexer->YYText();
    this->pos += strlen(text);

    if (tk == kgo::L_SPACE || tk == kgo::L_COMMENT) {
        return this->next(pointer);
    }

    auto ptoken = static_cast<kgo::Token **>(pointer);
    *ptoken = new kgo::Token(tk, text, line, pos);
    return tk;
};

void Scanner::set(kgo::Node *root) { this->root = root; }
void Scanner::error(const std::string &msg) {
    std::cout << "error: " << msg << std::endl;
};

bool Scanner::scan() {
    auto success = this->parser->parse() == 0;
    if (success) {
        this->root->print(0);
    }
    return success;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            i++;
        }
        std::cout << "Parse " << argv[i] << std::endl;
        auto scanner = std::make_unique<Scanner>(argv[i]);
        if (!scanner->scan()) {
            return 1;
        }
    }
    return 0;
}
