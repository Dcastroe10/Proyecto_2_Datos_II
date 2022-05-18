#ifndef QUEUE_H
#define QUEUE_H

#include <QDebug>

class queue
{
private:
    int* elements;
    int front;
    int rear;
    int size;
public:
    queue(int sizE);
    bool isEmpty();
    bool isFull();
    void enQueue(int num);
    int deQueue();
    int peek();
    int getSize() const;
};

#endif // QUEUE_H
