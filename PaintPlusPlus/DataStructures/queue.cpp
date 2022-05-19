#include "queue.h"

#include <QDebug>

bool queue::isEmpty()
{
    return nElements == 0;

}

void queue::enQueue(int value1) {
    node1* tmp = new node1;
    tmp->value = value1;
    if (isEmpty()) {
        front = tmp;
        rear = NULL;
    } else if (rear == NULL) {
        rear = tmp;
        front->next = rear;
    } else {
        rear->next = tmp;
        rear = tmp;
    }
    nElements++;
}

int queue::deQueue() {
    if (front == NULL) {
        return -1;
    }
    int ret = this->front->value;
    if (front->next == NULL) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }
    nElements--;
    return ret;
}






