#include "queue.h"

#include <QDebug>

/**
 * @brief Verifica si la queue está vacía o no
 * @return true si la queue está vacía, false si tiene al menos un elemento
 */
bool queue::isEmpty()
{
    return nElements == 0;

}

/**
 * @brief Agrega un elemento a la queue (al final de la misma)
 * @param value1    Valor que se desea agregar a la queue
 */
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

/**
 * @brief Obtiene el primer elemento de la queue
 * @return      El valor guardaro en el primer elemento de la queue
 */
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
