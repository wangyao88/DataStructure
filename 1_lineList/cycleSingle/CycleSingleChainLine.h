#ifndef DEMO_CYCLESINGLECHAINLINE_H
#define DEMO_CYCLESINGLECHAINLINE_H

typedef int Element;

typedef struct SNode {
    Element data;
    struct SNode *next;
} SNode, *SLinkList;

//****************************基本操作开始******************************
/**
 * 创建一个节点
 * @param data
 * @return
 */
SNode *createNode(Element data);

/**
 * 初始化循环单链表
 * @return
 */
SLinkList initSLinkList();

/**
 * 销毁循环单链表
 */
void destroySLinkList(SLinkList &list);

/**
 * 判断循环单链表是否为空
 * @param list
 * @return
 */
bool isEmpty(SLinkList &list);

/**
 * 循环单链表尾插法
 * @param list
 * @param data
 * @return 循环单链表
 */
SLinkList tailInsert(SLinkList &list, Element data);

/**
 * 循环单链表尾删法
 * @param list
 */
void tailDelete(SLinkList &list);

/**
 * 循环单链表头插法
 * @param list
 * @param data
 * @return
 */
SLinkList headInsert(SLinkList &list, Element data);

/**
 * 循环单链表头删法
 * @param list
 */
void headDelete(SLinkList &list);

/**
 * 获取循环单链表中与指定值相等的节点
 * @param list
 * @param data
 * @return
 */
SNode *finSNode(SLinkList &list, Element data);

/**
 * 在指定位置插入节点
 * @param index
 * @param data
 */
bool insertNode(SNode *index, Element data);

/**
 * 删除指定节点
 * @param index
 * @return
 */
bool deleteNode(SNode *index);

/**
 * 从头节点开始依次输出节点数值
 * @param list
 */
void printSLinkList(SLinkList list);

//****************************基本操作结束******************************


#endif //DEMO_CYCLESINGLECHAINLINE_H
