#include "ast.hpp"

namespace kgo {

Node::Node(Token *token, Node *left, Node *right) {
    this->token = token;
    this->left = left;
    this->right = right;
}

Node::Node(Token *token) { this->token = token; }

void Node::print(int level) {
    auto spaces = std::string();
    for (auto i = 0; i < level; i++) {
        spaces += "  ";
    }
    auto token = this->token;
    std::cout << spaces << token->token << " " << token->line << ":"
              << token->pos << " " << token->data << std::endl;
    if (this->left != nullptr) {
        this->left->print(level + 1);
    }
    if (this->right != nullptr) {
        this->right->print(level + 1);
    }
}
}
