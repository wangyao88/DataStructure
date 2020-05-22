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
SNode *createSNode(Element data);

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
 * @return 循环单链表
 */
SLinkList tailInsert(SLinkList &list);

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
 * 从头节点开始依次输出节点数值
 * @param list
 */
void printSLinkList(SLinkList list);

//****************************基本操作结束******************************

/**
 * 问题描述
 *    将循环单链表right链接到left之后，仍然保持链接形式
 *
 * 算法实现
 *    先找到两个循环单链表的尾指针，将left的尾指针与right的第一个节点链接起来，
 * 将right得的尾结点与left的头节点链接起来
 *
 * 算法总结
 *    时间复杂度为O(m+n)，空间复杂的为O(1)
 *
 * @param left
 * @param right
 * @return
 */
SLinkList concatSLinkList(SLinkList &left, SLinkList &right);

/**
 * 问题描述
 *    按升序顺序删除循环单链表
 *
 * 算法实现
 *    每循环一次，查找一个最小值节点（由minP指向最小值节点，minPre指向其前驱节点）并删除它。
 * 最后释放头节点
 *
 * 算法总结
 *    时间复杂度为O()，空间复杂的为O(1)
 *
 * @param list
 */
void iteratorDeleteMin(SLinkList &list);

#endif //DEMO_CYCLESINGLECHAINLINE_H
