//
// Created by amefodev on 27.07.2022.
//

#ifndef INC_116_POPULATION_CONNECT_NODE_H
#define INC_116_POPULATION_CONNECT_NODE_H
#include <iostream>
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
#endif //INC_116_POPULATION_CONNECT_NODE_H
