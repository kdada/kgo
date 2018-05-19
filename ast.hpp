#ifndef AST_H
#define AST_H

#include "token.hpp"
#include <iostream>

namespace kgo {

class Node {
  public:
    Token *token;
    Node *left;
    Node *right;
    Node(Token *token, Node *left, Node *right);
    Node(Token *token);
    void print(int level);
};
}

#endif
