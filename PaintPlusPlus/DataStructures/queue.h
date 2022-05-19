#ifndef QUEUE_H
#define QUEUE_H

#include <QDebug>
#include <iostream>

class queue
{
public:
    struct node1 {
        int value;
        node1* next = NULL;
    };

    node1* front = NULL;
    node1* rear = NULL;

    int nElements = 0;
    bool isEmpty();
    void enQueue(int value1);
    int deQueue();
};

#endif // QUEUE_H
