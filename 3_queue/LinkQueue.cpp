#include <cstdlib>
#include "LinkQueue.h"

//****************************基本操作开始******************************

void InitQueue(LinkQueue &queue) {
    queue.front = queue.rear = (LinkNode *) malloc(sizeof(LinkNode));
    queue.front->next = nullptr;
}

bool isEmpty(LinkQueue queue) {
    return queue.front == queue.rear;
}

void EnQueue(LinkQueue &queue, Element data) {
    auto newNode = (LinkNode *) malloc(sizeof(LinkNode));
    newNode->data = data;
    queue.rear->next = newNode;
    queue.rear = newNode;
}

bool DeQueue(LinkQueue &queue, Element &data) {
    if (isEmpty(queue)) {
        return false;
    }
    LinkNode *p = queue.front->next;
    data = p->data;
    queue.front->next = p->next;
    if (p == queue.rear) {
        queue.rear = queue.front;
    }
    free(p);
    return true;
}

//****************************基本操作结束******************************