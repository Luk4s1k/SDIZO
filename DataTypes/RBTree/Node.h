//
// Created by Luka Mitrovic on 03/05/2022.
//

#ifndef SDIZO_NODE_H
#define SDIZO_NODE_H

enum COLOR {RED,BLACK};
struct Node{
    int value;
    Node* leftSon;
    Node* rightSon;
    Node* parent;
    COLOR color;
//    Node(Node* parent, int value, Node* left, Node* right):parent(parent),value(value),leftSon(left), rightSon(right){};
//    Node();

};


#endif //SDIZO_NODE_H
