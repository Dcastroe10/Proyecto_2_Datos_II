#include "queue.h"

int queue::getSize() const
{
    return size;
}

queue::queue(int sizE)
{
    front = -1;
    rear = -1;
    elements = new int[sizE];
    size = sizE;
}

bool queue::isEmpty()
{
    if (front == -1) {
        return true;
    } else {
        return false;
    }
}

bool queue::isFull()
{
    if (rear == size - 1) {
        return true;
    } else {
        return false;
    }
}

void queue::enQueue(int num)
{
    if (isFull()) {
        //qDebug() << "MaxQueue";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        elements[rear] = num;
    }
}

int queue::deQueue() {
    if (isEmpty()) {
        qDebug() << "Queue empty";
        return -1;
    } else {
        int element;
        element = elements[front];
        if (front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return element;
    }
}

int queue::peek() {
    if (isEmpty()) {
        qDebug() << "Queue empty";
        return -1;
    } else {
        return elements[front];
    }
}






