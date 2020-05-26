#include "CycleQueue.h"


//****************************基本操作开始******************************

void InitQueue(CycleQueue &queue) {
    queue.front = queue.rear = 0;
}

/**
 * 判断循环队列是否为空
 * @param queue
 * @return
 */
bool isEmpty(CycleQueue queue) {
    return queue.front = queue.rear;
}

/**
 * 入队
 * @param queue
 * @param data
 * @return
 */
bool EnQueue(CycleQueue &queue, Element data) {
    if ((queue.rear + 1) % MaxSize == queue.front) {
        return false;
    }
    queue.data[queue.rear] = data;
    queue.rear = (queue.rear + 1) % MaxSize;
    return true;
}

/**
 * 出队
 * @param queue
 * @param data
 * @return
 */
bool DeQueue(CycleQueue &queue, Element &data) {
    if(isEmpty(queue)) {
        return false;
    }
    data = queue.data[queue.front];
    queue.front = (queue.front + 1) % MaxSize;
    return true;
}

//****************************基本操作结束******************************