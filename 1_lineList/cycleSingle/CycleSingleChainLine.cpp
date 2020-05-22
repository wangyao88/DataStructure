#include <cstdlib>
#include <iostream>
#include "CycleSingleChainLine.h"

using namespace std;

//****************************基本操作开始******************************

SNode *createSNode(Element data) {
    auto *node = (SNode *) malloc(sizeof(SNode));
    node->data = data;
    node->next = nullptr;
    return node;
}

SLinkList initSLinkList() {
    auto list = (SLinkList) malloc(sizeof(SLinkList) * 2);
    list->data = 0;
    list->next = list;
    return list;
}

void destroySLinkList(SLinkList &list) {
    SNode *p = list->next;
    while (p != list) {
        SNode *temp = p;
        p = p->next;
        free(temp);
    }
    free(list);
}

bool isEmpty(SLinkList &list) {
    return list->next == list;
}

SLinkList tailInsert(SLinkList &list) {
    SNode *s, *r = list;
    Element data;
    scanf("%d", &data);
    while (data != 999) {
        s = createSNode(data);
        r->next = s;
        r = s;
        scanf("%d", &data);
    }
    r->next = list;
    return list;
}

SLinkList headInsert(SLinkList &list, Element data) {
    SNode *currentNode = createSNode(data);
    currentNode->next = list->next;
    list->next = currentNode;
    return list;
}

void headDelete(SLinkList &list) {
    if (isEmpty(list)) {
        return;
    }
    SNode *currentNode = list->next;
    list->next = currentNode->next;
    free(currentNode);
}

SNode *finSNode(SLinkList &list, Element data) {
    SNode *p = list->next;
    while (p != nullptr) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void printSLinkList(SLinkList list) {
    if (isEmpty(list)) {
        cout << "循环单链表为空" << endl;
        return;
    }
    SNode *p = list->next;
    while (p != list) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
//****************************基本操作结束******************************

SLinkList concatSLinkList(SLinkList &left, SLinkList &right) {
    SNode *p = left, *q = right;
    while (p->next != left) {
        p = p->next;
    }
    while (q->next != right) {
        q = q->next;
    }
    p->next = right->next;
    q->next = left;
    return left;
}

void iteratorDeleteMin(SLinkList &list) {
    SNode *p, *pre, *minP, *minPre;
    while (list->next != list) {
        p = list->next;
        pre = list;
        minP = p;
        minPre = pre;
        while (p != list) {
            if(p->data < minP->data) {
                minP = p;
                minPre = pre;
            }
            p = p->next;
            pre = pre->next;
        }
        cout << minP->data << " ";
        minPre->next = minP->next;
        free(minP);
    }
    free(list);
}