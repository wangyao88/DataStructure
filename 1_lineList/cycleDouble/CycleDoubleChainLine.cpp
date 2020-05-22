#include <cstdlib>
#include <iostream>
#include "CycleDoubleChainLine.h"

using namespace std;

//****************************基本操作开始******************************

DNode *createNode(Element data) {
    auto *node = (DNode *) malloc(sizeof(DNode));
    node->data = data;
    node->prior = nullptr;
    node->next = nullptr;
    return node;
}

DLinkList initDLinkList() {
    //sizeof(DLinkList)*3 是因为DLinkList结构体包括三个DNode
    auto list = (DLinkList) malloc(sizeof(DLinkList) * 3);
    list->data = 0;
    list->prior = list;
    list->next = list;
    return list;
}

void destroyDLinkList(DLinkList &list) {
    DNode *p = list->next;
    while (p != list) {
        DNode *temp = p;
        p = p->next;
        free(temp);
    }
    free(list);
}

bool isEmpty(DLinkList &list) {
    return list->next == list && list->prior == list;
}

DLinkList tailInsert(DLinkList &list, Element data) {
    DNode *currentNode = createNode(data);
    list->prior->next = currentNode;
    currentNode->prior = list->prior;
    list->prior = currentNode;
    currentNode->next = list;
    return list;
}

void tailDelete(DLinkList &list) {
    if (isEmpty(list)) {
        return;
    }
    DNode *currentNode = list->prior;
    list->prior = currentNode->prior;
    currentNode->prior->next = list;
    free(currentNode);
}

DLinkList headInsert(DLinkList &list, Element data) {
    DNode *currentNode = createNode(data);
    currentNode->next = list->next;
    list->next->prior = currentNode;
    currentNode->prior = list;
    list->next = currentNode;
    return list;
}

void headDelete(DLinkList &list) {
    if (isEmpty(list)) {
        return;
    }
    DNode *currentNode = list->next;
    list->next = currentNode->next;
    currentNode->next->prior = list;
    free(currentNode);
}

DNode *findNode(DLinkList &list, Element data) {
    DNode *p = list->next;
    while (p != nullptr) {
        if(p->data == data) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

bool insertNode(DNode *index, Element data) {
    if(index == nullptr) {
        return false;
    }
    DNode * current = createNode(data);
    current->next = index->next;
    index->next->prior = current;
    current->prior = index;
    index->next = current;
    return true;
}

bool deleteNode(DNode *index) {
    if(index == nullptr) {
        return false;
    }
    index->prior->next = index->next;
    index->next->prior = index->prior;
    free(index);
    return true;
}

void printDLinkList(DLinkList list) {
    if (isEmpty(list)) {
        cout << "双向循环链表为空" << endl;
        return;
    }
    DNode *p = list->next;
    while (p != list) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

//****************************基本操作结束******************************

bool isSymmetry(DLinkList &list) {
    if(isEmpty(list)) {
        return true;
    }
    DNode *p = list->next, *q = list->prior;
    while (p != q && q->next != p) {
        //第二个条件写为p->next != q， 1 2 3 1， 2 3 不会比较数值而直接结束
        if(p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return false;
        }
    }
    return true;
}