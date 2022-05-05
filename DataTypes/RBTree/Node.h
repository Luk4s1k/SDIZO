//
// Created by Luka Mitrovic on 03/05/2022.
//

#ifndef SDIZO_NODE_H
#define SDIZO_NODE_H


struct Node{
    int value;
    Node* leftSon;
    Node* rightSon;
    Node* parent;
    int color;
    Node();


};


#endif //SDIZO_NODE_H
