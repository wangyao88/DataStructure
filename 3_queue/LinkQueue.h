#ifndef DEMO_LINK_QUEUE_H
#define DEMO_LINK_QUEUE_H

typedef int Element;

typedef struct LinkNode {
    Element data;
    struct LinkNode *next;
} LinkNode;

typedef struct LinkQueue {
    LinkNode *front, *rear;
} LinkQueue;

//****************************基本操作开始******************************

/**
 * 初始化链式队列
 * @param queue
 */
void InitQueue(LinkQueue &queue);

/**
 * 判断链式队列是否为空
 * @param queue
 * @return
 */
bool isEmpty(LinkQueue queue);

/**
 * 入队
 * @param queue
 * @param data
 */
void EnQueue(LinkQueue &queue, Element data);

/**
 * 出队
 * @param queue
 * @param data
 * @return
 */
bool DeQueue(LinkQueue &queue, Element &data);

//****************************基本操作结束******************************

#endif //DEMO_LINK_QUEUE_H
