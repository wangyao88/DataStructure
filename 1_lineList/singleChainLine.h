//
// Created by localadmin on 2020/5/9.
//

#ifndef DEMO_SINGLECHAINLINE_H
#define DEMO_SINGLECHAINLINE_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef int Element;

typedef struct LNode {
    Element data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 采用头插法建立单链表
 * 读入数据的顺序与生成链表的元素的顺序是相反的。
 * 每个节点插入的时间复杂度为O(1)，设单链表长度为n，则总时间复杂度为O(n)
 * @param list
 * @return
 */
LinkList headInsert(LinkList &list) {
    LNode *s;
    Element data;
    //创建头结点
    list = (LinkList) malloc(sizeof(LNode));
    //初始为空链表（头指针为NULL时，表示一个空链表）
    list->next = nullptr;
    scanf("%d", &data);
    while (data != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = data;
        s->next = list->next;
        list->next = s;
        scanf("%d", &data);
    }
    return list;
}

/**
 * 采用尾插法建立单链表
 * 读入数据的顺序与生成链表的元素的顺序是相同的
 * 每个节点插入的时间复杂度为O(1)，设单链表长度为n，则总时间复杂度为O(n)
 * @param list
 * @return
 */
LinkList tailInsert(LinkList &list) {
    Element data;
    list = (LinkList) malloc(sizeof(LNode));
    //r为表尾指针
    LNode *s, *r = list;
    scanf("%d", &data);
    while (data != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = data;
        r->next = s;
        //r指向新的表尾节点
        r = s;
        scanf("%d", &data);
    }
    //尾节点指针置空
    r->next = NULL;
    return list;
}

/**
 * 按序号查找单链表节点
 * 在单链表中从第一个节点出发，顺指针next域逐个往下搜索，直到找到第index个节点为止，否则返回最后一个节点指针域NULL
 * 时间复杂度为O(n)
 * @param list
 * @param index
 * @return
 */
LNode *getElement(LinkList list, int index) {
    if (index == 0) {
        return list;
    }
    if (index < 0) {
        return nullptr;
    }
    int j = 1;
    LNode *p = list->next;
    while (p && j < index) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找单链表节点
 * 在单链表中从第一个节点出发，顺指针next域逐个往下搜索，直到找到节点值为element为止，否则返回最后一个节点
 * 时间复杂度为O(n)
 * @param list
 * @param element
 * @return
 */
LNode *locateElement(LinkList list, Element element) {
    LNode *p = list->next;
    while (p != nullptr && p->data != element) {
        p = p->next;
    }
    return p;
}

/**
 * 求带头节点的单链表的长度
 * @param list
 * @return
 */
int length(LinkList &list) {
    int k = 0;
    LNode *p = list->next;
    while (p != nullptr) {
        k++;
        p = p->next;
    }
    return k;
}

/**
 * 输出单链表的所有元素
 *
 * @param list
 */
void print(LinkList list) {
    if (list == nullptr) {
        return;
    }
    for (LNode *p = list->next; p; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

/**
 * 递归删除元素值等于给定值的节点
 * @param list
 * @param element
 */
void recursiveDeleteNode(LinkList &list, Element element) {
    if (list == nullptr) {
        return;
    }
    LNode *p;
    if (list->data == element) {
        p = list;
        list = list->next;
        free(p);
        recursiveDeleteNode(list, element);
    } else {
        recursiveDeleteNode(list->next, element);
    }
}

/**
 * 问题描述
 *    在带头节点的单链表中。删除所有值为element的节点，并释放其空间。值为element的节点不唯一
 * 算法实现
 *    用p从头至尾扫描单链表，pre指向*p节点的前驱。若p所指节点的值为element，则删除，并让p移向下一个节点，否则让pre、p同步移向下一个节点
 * 算法总结
 *    本算法是在无序单链表中删除满足某种条件的所有节点，这里的条件是节点的值等于element。实际上这个条件是可以任意指定的，只要修改if条件即可。
 * 比如我们要删除值介于min和max之间的所有节点，则只需将if语句修改为if(p->data < max && p->data > min)
 *    时间复杂度为O(n)，空间复杂的为O(1)
 * @param list
 * @param element
 */
void deleteElement1(LinkList &list, Element element) {
    LNode *p = list->next, *pre = list, *q;
    while (p != nullptr) {
        if (p->data == element) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
 * 问题描述
 *    在带头节点的单链表中。删除所有值为element的节点，并释放其空间。值为element的节点不唯一
 * 算法实现
 *    采用尾插法建立单链表。用p指针扫描所有节点，当其值不为element时，将其链接到list之后，否则将其释放
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 * @param list
 * @param element
 */
void deleteElement2(LinkList &list, Element element) {
    LNode *p = list->next, *r = list, *q;
    while (p != nullptr) {
        if (p->data != element) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = nullptr;
}

/**
 * 问题描述
 *    从尾到头反向输出带头节点的单链表的每个节点的数据
 * 算法实现
 *    1 采用链表逆置法，改变链表的方向，然后从头到尾实现反向输出
 *    2 借助栈来实现。每经过一个节点，将它放到栈中。遍历完整个链表后，从栈顶开始输出节点即可（可使用递归）
 * 算法总结
 * @param list
 */
void reverseOutput(LinkList list) {
    if (list->next != nullptr) {
        reverseOutput(list->next);
    }
    cout << list->data << " ";
}

/**
 * 问题描述
 *    在带头节点的单链表中，删除最小值节点（最小值节点是唯一的）
 *
 * 算法实现
 *    用p从头至尾扫描单链表，pre指向p节点的前驱，用minp保存值最小的节点的指针（初值为p），minpre指向minp节点的前驱（初值为pre）。
 * 一边扫描一边比较，如果p->data值小于minp->data，则将p、pre赋值给minp和minpre。当p扫描完毕，minp指向最小值节点，minpre指向最
 * 小值节点的前驱节点，再将minp所指节点删除即可
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 */
void deleteMin(LinkList &list) {
    LNode *pre = list, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != nullptr) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

/**
 * 问题描述
 *    将带头节点的单链表就地逆置，“就地”是指辅助空间复杂度为O(1)
 *
 * 算法实现
 *    将头节点摘下，然后从第一个节点开始，依次插入到头节点后面（头插法建立单链表），直到最后一个节点为止。
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 */

void reverseList1(LinkList &list) {
    LNode *p, *r;
    p = list->next;
    list->next = nullptr;
    while (p != nullptr) {
        r = p->next;
        p->next = list->next;
        list->next = p;
        p = r;
    }
}

/**
 * 问题描述
 *    将带头节点的单链表就地逆置，“就地”是指辅助空间复杂度为O(1)
 *
 * 算法实现
 *    调整指针方向。从第一个节点开始遍历，每次摘下一个节点（p指向），其后继节点为r，前驱节点为pre，
 * 然后改变p的next指针为pre，然后pre、p、r依次后移一位
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 */
void reverseList2(LinkList &list) {
    LNode *pre, *p = list->next, *r = p->next;
    p->next = nullptr;
    while (r != nullptr) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    list->next = p;
}

/**
 * 问题描述
 *    将带头节点的单链表升序排序
 *
 * 算法实现
 *    采用直接插入排序的算法的思想，先构成只含一个节点的有序单链表，然后依次扫描单链表剩下的节点p，直到表尾，
 * 在有序表中通过比较查找插入p的前驱节点pre，然后将p插到pre之后
 *
 * 算法总结
 *    时间复杂度为O(n平方)，空间复杂的为O(1)
 *
 * @param list
 */
void sort(LinkList &list) {
    LNode *p = list, *pre;
    LNode *r = p->next;
    p->next = nullptr;
    p = r;
    while (p != nullptr) {
        r = p->next;
        pre = list;
        while (pre->next != nullptr && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}

/**
 * 问题描述
 *    在带头节点的无序单链表中，删除所有介于给定的两个值之间
 *
 * 算法实现
 *    因为链表无序，只能逐个节点进行检查，执行删除
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 * @param min
 * @param max
 */
void rangeDelete(LinkList &list, Element min, Element max) {
    LNode *pre = list, *p = list->next;
    while (p != nullptr) {
        if (p->data > min && p->data < max) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
 * 问题描述
 *    找出两个单链表的公共节点
 *
 * 算法实现
 *
 * 算法总结
 *    时间复杂度为O(leftLength+rightLength)，空间复杂的为O(1)
 *
 * @param leftList
 * @param rightList
 * @return
 */
LinkList searchCommonNodes(LinkList leftList, LinkList rightList) {
    int leftLength = length(leftList), rightLength = length(rightList);
    int diss = 0;
    LinkList longList, shortList;
    if (leftLength > rightLength) {
        longList = leftList->next;
        shortList = rightList->next;
        diss = leftLength - rightLength;
    } else {
        longList = rightList->next;
        shortList = leftList->next;
        diss = rightLength - leftLength;
    }
    while (diss--) {
        longList = longList->next;
    }
    while (longList != nullptr) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return nullptr;
}

/**
 * 问题描述
 *    按升序删除带头节点的单链表的节点
 *
 * 算法实现
 *    对单链表进行遍历，在每次遍历中找出整个链表的最小节点，输出并释放节点占用的空间。
 * 如此往复，直到直到链表为空，最后释放头节点所占空间
 *
 * 算法总结
 *    时间复杂度为O(n平方)，空间复杂的为O(1)
 *
 * @param head
 */
void minIteratorDelete(LinkList &head) {
    LNode *pre, *p, *del;
    while (head->next != nullptr) {
        pre = head;
        p = pre->next;
        while (p->next != nullptr) {
            if (p->next->data < pre->next->data) {
                pre = p;
            }
            p = p->next;
        }
        cout << pre->next->data << " ";
        del = pre->next;
        pre->next = del->next;
        free(del);
    }
    free(head);
}

/**
 * 问题描述
 *    将带头节点的单链表按奇偶顺序分解成两个带头节点的单链表
 *
 * 算法实现
 *    对单链表进行遍历，采用尾插法依次插入连个单链表
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param A
 * @return
 */
LinkList separate(LinkList &A) {
    auto B = (LinkList) malloc(sizeof(LNode));
    LNode *ra = A, *rb = B;
    LNode *p = A->next;
    A->next = nullptr;
    while (p != nullptr) {
        // 改变A和ra的next
        ra->next = p;
        //指向p指向的节点
        ra = p;
        p = p->next;
        if (p != nullptr) {
            rb->next = p;
            rb = p;
            p = p->next;
        }
    }
    ra->next = nullptr;
    rb->next = nullptr;
    return B;
}

/**
 * 问题描述
 *    将带头节点的单链表按奇偶顺序分解成两个带头节点的单链表，第二个单链表逆序
 *
 * 算法实现
 *    对单链表进行遍历，第一个单链表采用尾插法依次插入节点，第二个单链表采用头插法依次插入节点
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param A
 * @return
 */
LinkList separateSort(LinkList &A) {
    auto B = (LinkList) malloc(sizeof(LNode));
    B->next = nullptr;
    LNode *p = A->next, *q;
    //ra始终指向A的尾节点
    LNode *ra = A;
    while (p != nullptr) {
        //将p链到A的表尾
        ra->next = p;
        ra = p;

        p = p->next;
        if (p != nullptr) {
            //头插后，*p将断链，用q记忆p的后继节点
            q = p->next;
            //将*p插入到B的前端
            p->next = B->next;
            B->next = p;
            p = q;
        }
    }
    ra->next = nullptr;
    return B;
}

/**
 * 问题描述
 *    删除递增单链表数值重复的节点，只保留一个
 *
 * 算法实现
 *    由于是有序表，所有相同值域的节点都是相邻的。对单链表进行遍历，
 * 当前节点值域等于后继节点值域，则当前节点移动到后继节点的后继节点，
 * 删除后继节点，否则向后移动一个节点
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 */
void distinct(LinkList &list) {
    LNode *p = list->next, *q;
    if (p == nullptr) {
        return;
    }
    while (p->next != nullptr) {
        q = p->next;
        if (p->data == q->data) {
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

/**
 * 问题描述
 *    合并两个按递增次序排序的单链表，合并后的链表按照递减次序排序
 *
 * 算法实现
 *    两个链表已经按递增次序排序，将其排序，均从第一个节点起进行比较。
 * 将小的节点链入链表中，同时后移工作指针。
 *    要求结果链表按元素值递减次序排序，故新链表建立采用头插法。
 *    比较结束后，可能会有一个链表非空，此时用头插法将剩下的节点依次插入新链表中
 *
 * 算法总结
 *    时间复杂度为O(max(m,n))，空间复杂的为O(1)
 *
 * @param left
 * @param right
 */
LinkList mergeAndReverse(LinkList &left, LinkList &right) {
    LNode *r, *pLeft = left->next, *pRight = right->next;
    left->next = nullptr;
    while (pLeft && pRight) {
        if (pLeft->data <= pRight->data) {
            r = pLeft->next;
            pLeft->next = left->next;
            left->next = pLeft;
            pLeft = r;
        } else {
            r = pRight->next;
            pRight->next = left->next;
            left->next = pRight;
            pRight = r;
        }
    }
    if (pLeft) {
        pRight = pLeft;
    }
    while (pRight) {
        r = pRight->next;
        pRight->next = left->next;
        left->next = pRight;
        pRight = r;
    }
    free(right);
    return left;
}

/**
 * 问题描述
 *    用两个带头节点的递增的单链表的公共节点组成一个新的单链表，要求不破坏原单链表节点
 *
 * 算法实现
 *    两个单链表均有序，可从第一个元素起依次比较两表的元素，若元素值不等，则后移元素值较小的节点。
 * 若元素值相等，则创建一个值等于两节点值得新节点，并采用尾插发链入到新单链表尾部，并将两个原表指针
 * 都后移一位，直到其中一个链表移动到表尾
 *
 * 算法总结
 *    时间复杂度为O(min(m,n))，空间复杂的为O(1)
 *
 * @param left
 * @param right
 * @return
 */
LinkList getCommon(LinkList &left, LinkList &right) {
    LNode *p = left->next, *q = right->next, *r, *s;
    auto common = (LinkList) malloc(sizeof(LNode));
    //r始终指向common的尾节点
    r = common;
    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            p = p->next;
        } else if (p->data < q->data) {
            q = q->next;
        } else {
            //找到公共元素节点
            s = (LNode *) malloc(sizeof(LNode));
            s->data = p->data;
            //将s链接到common（尾插法）
            r->next = s;
            r = s;
            p = p->next;
            q = q->next;
        }
    }
    r->next = nullptr;
    return common;
}

/**
 * 问题描述
 *    递增排序的两个链表表示两个集合，求其交集，并存放于第一个链表中
 *
 * 算法实现
 *    采用归并的思想，设置两个工作指针，对两个链表进行归并扫描，只有同时出现
 * 在两个链表中的元素才链接到结果链表中，且仅保留一个。其他的节点全部释放。
 *    当一个链表遍历完成后，释放另一个链表中剩余的全部节点
 *
 * 算法总结
 *    时间复杂度为O(m+n)，空间复杂的为O(1)
 *
 * @param left
 * @param right
 * @return
 */
LinkList unionSet(LinkList &left, LinkList &right) {
    LNode *pTemp, *pLeft = left->next, *pRight = right->next,
    //结果表中当前合并节点的前驱节点
    *pUnion = left;
    while (pLeft && pRight) {
        if (pLeft->data == pRight->data) {
            pUnion->next = pLeft;
            pUnion = pLeft;
            pLeft = pLeft->next;
            pTemp = pRight;
            pRight = pRight->next;
        } else if (pLeft->data < pRight->data) {
            pTemp = pLeft;
            pLeft = pLeft->next;
        } else {
            pTemp = pRight;
            pRight = pRight->next;
        }
        free(pTemp);
    }
    while (pLeft) {
        pTemp = pLeft;
        pLeft = pLeft->next;
        free(pTemp);
    }
    while (pRight) {
        pTemp = pRight;
        pRight = pRight->next;
        free(pTemp);
    }
    pUnion->next = nullptr;
    free(right);
    return left;
}

/**
 * 问题描述
 *    有两个单链表，判断第二个单链表是否是第一个单链表的子序列
 *
 * 算法实现
 *    从两个单链表的第一个节点开始遍历，若对应数据相等，则后移指针，
 * 否则第一个链表从上次开始比较节点的后继节点开始，第二个链表仍然从第一个节点开始比较，
 * 直到第二个链表到表尾表示匹配成功。
 *    第一个链表到表尾，而第二个链表未到表尾，表示匹配失败。
 *    操作中应记住第一个链表每次开始的节点，以便下次匹配时从其后继节点开始。
 *
 * 算法总结
 *    时间复杂度为O(min(mxn))，空间复杂的为O(1)
 *
 * @param left
 * @param right
 * @return true right是left的子序列 right不是left的子序列
 */
bool pattern(LinkList &left, LinkList &right) {
    LNode *pLeft = left, *pRight = right, *pStart = pLeft;
    while (pLeft && pRight) {
        if (pLeft->data == pRight->data) {
            pLeft = pLeft->next;
            pRight = pRight->next;
        } else {
            pStart = pStart->next;
            pLeft = pStart;
            pRight = right;
        }
    }
    return pRight == nullptr;
}

/**
 * 问题描述
 *    查找单链表倒数第k个位置上的节点
 *
 * 算法实现
 *    指针p,q都指向头节点， 让p先移动k个位置，然后p和q一起往后移动。
 * 如果p能够移动k个位置，则查找成功。算法思想类似时间滑动窗口
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 * @param k
 * @return
 */
bool searchK(LinkList &list, int k) {
    LNode *p = list->next, *q = list->next;
    int count = 0;
    while (p != nullptr) {
        if(count < k) {
            count++;
        } else {
            q = q->next;
        }
        p = p->next;
    }
    if(count < k) {
        return false;
    }
    printf("%d", q->data);
    return true;
}

/**
 * 问题描述
 *    查找两个单链表共链
 *
 * 算法实现
 *    用指针p，q分别扫描left和right，当两个指针指向同一个节点时，即找到了共链
 *
 * 算法总结
 *    时间复杂度为O(m+n)，空间复杂的为O(1)
 *
 * @param left
 * @param right
 * @return
 */
LNode *findCommonNode(LinkList &left, LinkList &right) {
    LNode *p, *q;
    int m = length(left);
    int n = length(right);
    for(p = left; m > n; m--) {
        p = p->next;
    }
    for(q = right; m < n; n--) {
        q = q->next;
    }
    while (p->next != nullptr && p->next->data != q->next->data) {
//        p->next != q->next 此应为第二个条件，简便起见比较数值
        p = p->next;
        q = q->next;
    }
    return p;
}

/**
 * 问题描述
 *    删除单链表数值重复出现的节点，仅保留第一次出现的节点
 *
 * 算法实现
 *    空间换时间，使用辅助数组记录绝对值下标的值，0表示未出现，1表示出现过，则删除当前节点
 *
 * 算法总结
 *    时间复杂度为O(n)，空间复杂的为O(1)
 *
 * @param list
 */
LinkList deleteNodeWithSameAbsData(LinkList &list, int max) {
    int num[max+1];
    for (int i = 0; i <= max; i++) {
        num[i] = 0;
    }
    LNode *p = list->next, *pre = list, *temp;
    while (p != nullptr) {
        if(num[abs(p->data)] == 0) {
            num[abs(p->data)] = 1;
            p = p->next;
            pre = pre->next;
        } else {
            temp = p;
            pre->next = p->next;
            p = p->next;
            free(temp);
        }
    }
    return list;
}

#endif //DEMO_SINGLECHAINLINE_H
