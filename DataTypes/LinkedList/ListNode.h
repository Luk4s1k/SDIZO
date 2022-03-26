//
// Created by Luka Mitrovic on 14/03/2022.
//

#ifndef SDIZO_LISTNODE_H
#define SDIZO_LISTNODE_H


class ListNode {
public:
    ListNode(int value, int *next, int* prev):value(value),next(next),prev(prev){};
private:
    int *next;
    int *prev;
    int value;
};


#endif //SDIZO_LISTNODE_H
