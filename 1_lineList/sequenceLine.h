//
// Created by localadmin on 2020/4/29.
//

#ifndef DEMO_SEQUENCELINE_H
#define DEMO_SEQUENCELINE_H

using namespace std;

#define INIT_SIZE 100

typedef int Element;

typedef struct SeqList {
    Element *data;
    int maxSize, length;
} SeqList;

void initList(SeqList &list, int maxSize = INIT_SIZE) {
    list.data = new Element[maxSize];
    list.length = 0;
    list.maxSize = maxSize;
}

bool insertList(SeqList &list, int index, Element element) {
    if (index < 1 || index > list.length + 1) {
        return false;
    }
    if (list.length > list.maxSize) {
        return false;
    }
    for (int i = list.length; i >= index; i--) {
        list.data[i] = list.data[i - 1];
    }
    list.data[index - 1] = element;
    list.length++;
    return true;
}

bool deleteList(SeqList &list, int index, Element &element) {
    if (index < 1 || index > list.length) {
        return false;
    }
    element = list.data[index - 1];
    for (int i = index; i < list.length; i++) {
        list.data[i - 1] = list.data[i];
    }
    list.length--;
    return true;
}

int locateElement(SeqList &list, Element element) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == element) {
            return i;
        }
    }
    return 0;
}

int length(SeqList &list) {
    return list.length;
}

bool empty(SeqList &list) {
    return list.length == 0;
}

void destroyList(SeqList &list) {
    delete[] list.data;
}

void print(SeqList &list) {
    for (int i = 0; i < list.length; i++) {
//        cout << list.data[i] << " ";
    }
}

/**
 * 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删元素的值，空出的位置由最后一个位置的元素填补
 * 若顺序表为空，则显示出错信息并退出运行
 * @param list
 * @param element
 * @return true: 删除成功， false: 删除失败
 */
bool deleteMin(SeqList &list, Element &element) {
    if (list.length == 0) {
        return false;
    }
    element = list.data[0];
    int index = 0;
    for (int i = 1; i < list.length; i++) {
        if (element > list.data[i]) {
            element = list.data[i];
            index = i;
        }
    }
    list.data[index] = list.data[list.length - 1];
    list.length--;
    return true;
}

/**
 * 将顺序表List的所有元素逆置
 * @param list
 */
void transpose(SeqList &list) {
    if (list.length == 0) {
        return;
    }
    int centrePosition = list.length / 2;
    Element temp;
    for (int i = 0; i < centrePosition; i++) {
        temp = list.data[i];
        list.data[i] = list.data[list.length - i - 1];
        list.data[list.length - i - 1] = temp;
    }
}

/**
 * 顺序表删除与指定元素相等的所有元素
 * @param list
 * @param element
 */
void delEquals(SeqList &list, Element element) {
    int position = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] != element) {
            list.data[position] = list.data[i];
            position++;
        }
    }
    list.length = position;
}

/**
 * 顺序表删除指定值区间内的元素
 * @param list
 * @param start
 * @param end
 * @return
 */
bool delRange(SeqList &list, Element start, Element end) {
    if (list.length == 0 || start >= end) {
        return false;
    }
    int position = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] < start || list.data[i] > end) {
            list.data[position] = list.data[i];
            position++;
        }
    }
    list.length = position;
    return true;
}

/**
 * 删除有序顺序表中重复元素，删除后，表中所有元素各不相同
 * @param list
 */
void delRepeat(SeqList &list) {
    if (list.length == 0) {
        return;
    }
    int position = 0;
    for (int i = 0; i < list.length; i++) {
        if (list.data[position] != list.data[i]) {
            list.data[position + 1] = list.data[i];
            position++;
        }
    }
    list.length = position + 1;
}

/**
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果有序顺序表
 * @param leftList
 * @param rightList
 * @param resultList
 * @return
 */
bool merge(SeqList leftList, SeqList rightList, SeqList &resultList) {
    if (leftList.length + rightList.length > resultList.maxSize) {
        return false;
    }
    int leftIndex = 0, rightIndex = 0, resultIndex = 0;
    while (leftIndex < leftList.length && rightIndex < rightList.length) {
        while (leftList.data[leftIndex] <= rightList.data[rightIndex] && leftIndex < leftList.length) {
            resultList.data[resultIndex++] = leftList.data[leftIndex++];
        }
        while (rightList.data[rightIndex] < leftList.data[leftIndex] && rightIndex < rightList.length) {
            resultList.data[resultIndex++] = rightList.data[rightIndex++];
        }
    }
    for (; leftIndex < leftList.length; leftIndex++) {
        resultList.data[resultIndex++] = leftList.data[leftIndex];
    }
    for (; rightIndex < rightList.length; rightIndex++) {
        resultList.data[resultIndex++] = rightList.data[rightIndex];
    }
    resultList.length = resultIndex;
    return true;
}

/**
 * 顺序表逆置指定区间内元素
 * @param list
 */
bool transposeRange(SeqList &list, int start, int end) {
    if (list.length == 0 || start >= end) {
        return false;
    }
    start = start < 1 ? 0 : start - 1;
    end = end > list.length ? list.length - 1 : end - 1;
    int centrePosition = (end + start) / 2 - start + 1;
    Element temp;
    for (int i = 0; i < centrePosition; i++) {
        temp = list.data[start + i];
        list.data[start + i] = list.data[end - i];
        list.data[end - i] = temp;
    }
    return true;
}

int majority(int A[], int n) {
    int i, c, count = 1;
    c = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] == c) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                c = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        for (i = count = 0; i < n; i++) {
            if (A[i] == c) {
                count++;
            }
        }
    }
    return count > n / 2 ? c : -1;
}

#endif //DEMO_SEQUENCELINE_H
