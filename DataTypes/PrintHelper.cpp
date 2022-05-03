//
// Created by Luka Mitrovic on 03/05/2022.
//
#include "PrintHelper.h"
void PrintHelper::printLevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void PrintHelper::test(){
    printLevelOrder(tree->getRoot());
    this->arr->print();
};


void PrintHelper::printCurrentLevel(Node *root, int level) {
    if (root == tree->getNullNode())
        return;
    if (level == 1){
        if(root->color == RED){
            this->arr->push_back(root->value);
        }else if(root->color == BLACK){
            this->arr->push_back(root->value * (-1));
        }
    }

    else if (level > 1) {
        printCurrentLevel(root->leftSon, level - 1);
        printCurrentLevel(root->rightSon, level - 1);
    }
}

int PrintHelper::height(Node *node) {
    if (node == tree->getNullNode())
        return 0;
    else {
        int lheight = height(node->leftSon);
        int rheight = height(node->rightSon);

        if (lheight > rheight) {
            return (lheight + 1);
        } else {
            return (rheight + 1);
        }
    }
}

std::string PrintHelper::do_padding(unsigned index, unsigned mlength) {
    std::string padding;
    if (int((index - 1) / 2) != 0) {
        return (int((index - 1) / 2) % 2 == 0) ?
               (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 4, ' ') + " ") :
               (do_padding(int((index - 1) / 2), mlength) + std::string(mlength + 3, ' ') + " |");
    }
    return padding;
}


void PrintHelper::printer(unsigned index, unsigned mlength) {
    auto last = arr->getSize() - 1;
    auto left = 2 * index + 1;
    auto right = 2 * index + 2;
    std::cout << " " << *arr->at(index) << " ";
    if (left <= last) {
        auto llength = std::to_string(*arr->at(left)).size();
        std::cout << "---" << std::string(mlength - llength, '-');
        printer(left, mlength);
        if (right <= last) {
            auto rlength = std::to_string(*arr->at(right)).size();
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " | ";
            std::cout << "\n" << do_padding(right, mlength) << std::string(mlength + 3, ' ') << " └" <<
                      std::string(mlength - rlength, '-');
            printer(right, mlength);
        }
    }
}

void PrintHelper::print_tree() {
    unsigned mlength = 0;
    for (int i = 0; i < arr->getSize(); i++) {
        auto clength = std::to_string(*arr->at(i)).size();
        if (clength > mlength) {
            mlength = std::to_string(*arr->at(i)).size();
        }
    }
    std::cout << std::string(mlength - std::to_string(*arr->at(0)).size(), ' ');
    printer(0, mlength);
    std::cout << std::endl;
}

PrintHelper::PrintHelper(RBTree *tree) {
    this->tree = tree;
    this->arr = new Array();
}