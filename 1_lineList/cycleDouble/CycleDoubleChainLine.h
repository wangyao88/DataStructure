#ifndef DEMO_CYCLEDOUBLECHAINLINE_H
#define DEMO_CYCLEDOUBLECHAINLINE_H

typedef int Element;

typedef struct DNode {
    Element data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//****************************基本操作开始******************************
/**
 * 创建一个节点
 * @param data
 * @return
 */
DNode *createNode(Element data);

/**
 * 初始化循环双链表
 * @return
 */
DLinkList initDLinkList();

/**
 * 销毁循环双链表
 */
void destroyDLinkList(DLinkList &list);

/**
 * 判断循环双链表是否为空
 * @param list
 * @return
 */
bool isEmpty(DLinkList &list);

/**
 * 循环双链表尾插法
 * @param list
 * @param data
 * @return 循环双链表
 */
DLinkList tailInsert(DLinkList &list, Element data);

/**
 * 循环双链表尾删法
 * @param list
 */
void tailDelete(DLinkList &list);

/**
 * 循环双链表头插法
 * @param list
 * @param data
 * @return
 */
DLinkList headInsert(DLinkList &list, Element data);

/**
 * 循环双链表头删法
 * @param list
 */
void headDelete(DLinkList &list);

/**
 * 获取循环双链表中与指定值相等的节点
 * @param list
 * @param data
 * @return
 */
DNode *findNode(DLinkList &list, Element data);

/**
 * 在指定位置插入节点
 * @param index
 * @param data
 */
bool insertNode(DNode *index, Element data);

/**
 * 删除指定节点
 * @param index
 * @return
 */
bool deleteNode(DNode *index);

/**
 * 从头节点开始依次输出节点数值
 * @param list
 */
void printDLinkList(DLinkList list);

//****************************基本操作结束******************************

/**
 * 问题描述
 *    循环双链表是否对称
 *
 * 算法实现
 *    p从头到尾方向扫描，q从尾到头方向扫描，直到他们指向同一个节点
 *（p == q, 当循环双链表节点个数为奇数时）或相邻（p->next == q 或 q->prior == p 当循环双链表节点个数为奇数时）为止，
 *    若他们所指节点值相同，则继续下去，否则返回false。若全部比较相等，则返回true
 *
 * 算法总结
 *    时间复杂度为O(log2n)，空间复杂的为O(1)
 *
 * @param list
 * @return
 */
bool isSymmetry(DLinkList &list);

#endif //DEMO_CYCLEDOUBLECHAINLINE_H
