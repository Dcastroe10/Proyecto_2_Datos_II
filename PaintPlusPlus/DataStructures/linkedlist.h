#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>

class linkedList
{
private:
    node *head = NULL;
    int size = 0;
public:
    linkedList();
    void addCoords(int x, int y);
    int* getCoords(int index);
    int deleteData(int index);
    void deleteLastData();
    int getSize();
};

#endif // LINKEDLIST_H
