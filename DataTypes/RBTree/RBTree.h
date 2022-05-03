//
// Created by Luka Mitrovic on 03/05/2022.
//

#ifndef SDIZO_RBTREE_H
#define SDIZO_RBTREE_H
#include <string>
#include "Node.h"
#include <iostream>
//#include "../PrintHelper.h"

class RBTree {
public:
    RBTree();
    ~RBTree();
    explicit RBTree(const std::string &filename);

    void rotateRight(Node* x);
    void rotateLeft(Node* x);

    Node* search(Node* node,int value);

    void insertElement(int value);
    void fixAfterInsertion(Node* k);

    void removeElement(Node *node, int value);
    void fixAfterRemoval(Node* x);

    Node *postOrder(Node *node);

    void swap(Node * a, Node* b);
    Node * minimum(Node* node);
    void print();
    Node* getRoot();
    Node* getNullNode();
private:
    Node *root;
    Node* nullNode;

};


#endif //SDIZO_RBTREE_H
