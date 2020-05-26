#ifndef DEMO_CYCLEQUEUE_H
#define DEMO_CYCLEQUEUE_H

#define MaxSize 100

typedef int Element;

typedef struct CycleQueue {
    Element data[MaxSize];
    int front, rear;
} CycleQueue;

//****************************基本操作开始******************************

/**
 * 初始化循环队列
 * @param queue
 */
void InitQueue(CycleQueue &queue);

/**
 * 判断循环队列是否为空
 * @param queue
 * @return
 */
bool isEmpty(CycleQueue queue);

/**
 * 入队
 * @param queue
 * @param data
 * @return
 */
bool EnQueue(CycleQueue &queue, Element data);

/**
 * 出队
 * @param queue
 * @param data
 * @return
 */
bool DeQueue(CycleQueue &queue, Element &data);

//****************************基本操作结束******************************
#endif //DEMO_CYCLEQUEUE_H
