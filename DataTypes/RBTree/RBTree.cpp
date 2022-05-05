//
// Created by Luka Mitrovic on 03/05/2022.
//

#include "RBTree.h"
#include <fstream>

RBTree::RBTree() {
    this->nullNode = new Node();
    this->nullNode->color = 0;
    this->nullNode->leftSon = nullNode;
    this->nullNode->rightSon = nullNode;
    this->nullNode->parent = nullNode;
    this->root = nullNode;
}

RBTree::~RBTree() {
    delete postOrder(root);
}

void RBTree::rotateLeft(Node* x) {
    Node* y = x->rightSon;
    x->rightSon = y->leftSon;
    if (y->leftSon != nullNode) {
        y->leftSon->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->leftSon) {
        x->parent->leftSon = y;
    } else {
        x->parent->rightSon = y;
    }
    y->leftSon = x;
    x->parent = y;
}

void RBTree::rotateRight(Node *x) {
    Node* y = x->leftSon;
    x->leftSon = y->rightSon;
    if (y->rightSon != nullNode) {
        y->rightSon->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->rightSon) {
        x->parent->rightSon = y;
    } else {
        x->parent->leftSon = y;
    }
    y->rightSon = x;
    x->parent = y;
}


Node *RBTree::postOrder(Node *node) {
    if (node == nullNode)
        return node;
    postOrder(node->leftSon);
    postOrder(node->rightSon);
   return node;
}

void RBTree::removeElement(Node *node,int key) {
    Node* z = nullNode;
    Node* x;
    Node *y;
    while (node != nullNode){
        if (node->value == key) {
            z = node;
        }

        if (node->value <= key) {
            node = node->rightSon;
        } else {
            node = node->leftSon;
        }
    }

    if (z == nullNode) {
        return;
    }

    y = z;
    int initialColorOf_Y = y->color;
    if (z->leftSon == nullNode) {
        x = z->rightSon;
        swap(z, z->rightSon);
    } else if (z->rightSon == nullNode) {
        x = z->leftSon;
        swap(z, z->leftSon);
    } else {
        y = minimum(z->rightSon);
        initialColorOf_Y = y->color;
        x = y->rightSon;
        if (y->parent == z) {
            x->parent = y;
        } else {
            swap(y, y->rightSon);
            y->rightSon = z->rightSon;
            y->rightSon->parent = y;
        }

        swap(z, y);
        y->leftSon = z->leftSon;
        y->leftSon->parent = y;
        y->color = z->color;
    }
    delete z;
    if (initialColorOf_Y == 0){
        fixAfterRemoval(x);
    }

}

void RBTree::fixAfterRemoval(Node* x) {
    Node * s;
    while (x != root && x->color == 0) {
        if (x == x->parent->leftSon) {
            s = x->parent->rightSon;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rotateLeft(x->parent);
                s = x->parent->rightSon;
            }

            if (s->leftSon->color == 0 && s->rightSon->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->rightSon->color == 0) {
                    s->leftSon->color = 0;
                    s->color = 1;
                    rotateRight(s);
                    s = x->parent->rightSon;
                }
                s->color = x->parent->color;
                x->parent->color = 0;
                s->rightSon->color = 0;
                rotateLeft(x->parent);
                x = root;
            }
        } else {
            s = x->parent->leftSon;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rotateRight(x->parent);
                s = x->parent->leftSon;
            }

            if (s->rightSon->color == 0 && s->rightSon->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->leftSon->color == 0) {
                    s->rightSon->color = 0;
                    s->color = 1;
                    rotateLeft(s);
                    s = x->parent->leftSon;
                }
                s->color = x->parent->color;
                x->parent->color = 0;
                s->leftSon->color = 0;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}



void RBTree::insertElement(int key) {
        Node* node = new Node();
        node->parent = nullptr;
        node->value = key;
        node->leftSon = nullNode;
        node->rightSon = nullNode;
        node->color = 1;
        if(root == nullptr){
            root = node;
            root->color = 0;
            return;
        }

        Node* y = nullptr;
        Node* x = this->root;

        while (x != nullNode) {
            y = x;
            if (node->value < x->value) {
                x = x->leftSon;
            } else {
                x = x->rightSon;
            }
        }
        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->value < y->value) {
            y->leftSon = node;
        } else {
            y->rightSon = node;
        }

        if (node->parent == nullptr){
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        fixAfterInsertion(node);
}

void RBTree::fixAfterInsertion(Node * k) {
        Node* u = new Node();
        while (k->parent != nullNode && k->parent->color == 1) {
            if (k->parent == k->parent->parent->rightSon) {
                u = k->parent->parent->leftSon;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->leftSon) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rotateLeft(k->parent->parent);
                }
            } else {
                u = k->parent->parent->rightSon;

                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->rightSon) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 0;
                    rotateRight(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;

}

void RBTree::swap(Node * a, Node* b) {
        if (a->parent == nullptr) {
            root = b;
        } else if (a == a->parent->leftSon){
            a->parent->leftSon = b;
        } else {
            a->parent->rightSon = b;
        }
        b->parent = a->parent;
}

Node* RBTree::minimum(Node* node) {
    while (node->leftSon != nullNode) {
        node = node->leftSon;
    }
    return node;
}


RBTree::RBTree(const std::string &filename) {
    this->nullNode = new Node();
    this->nullNode->color = 0;
    this->nullNode->leftSon = nullNode;
    this->nullNode->rightSon = nullNode;
    this->nullNode->parent = nullNode;
    this->root = nullNode;
    std::ifstream file;
    int treeSizeFormFile;
    int readVal;
    file.open(filename);
    if (file.is_open()) {
        file >> treeSizeFormFile;
        for (int i = 0; i < treeSizeFormFile; i++) {
            file >> readVal;
            insertElement(readVal);
        }
    }
    file.close();
}

Node *RBTree::getRoot() {
    return this->root;
}

Node *RBTree::search(Node *node, int value) {
    if (node == nullNode || value == node->value) {
        return node;
    }

    if (value < node->value) {
        return search(node->leftSon, value);
    }
    return search(node->rightSon, value);

}

Node *RBTree::getNullNode() {
    return this->nullNode;
}

void RBTree::print(const std::string& prefix, const Node* node, bool isLeft)
{
    if( node != nullNode )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        if(node->color == 0){
            std::cout << node->value << " BLACK "<< std::endl;
        }else {
            std::cout << node->value << " RED "<< std::endl;
        }
        print( prefix + (isLeft ? "│   " : "    "), node->leftSon, true);
        print( prefix + (isLeft ? "│   " : "    "), node->rightSon, false);
    }
}

void RBTree::print(const Node* node)
{
    print("", node, false);
}



