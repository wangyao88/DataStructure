#include <cstdlib>
#include <iostream>
#include "SequentialStack.h"

using namespace std;

//****************************基本操作开始******************************

void InitStack(SequentialStack &stack) {
    //初始化栈顶指针
    stack.top = -1;
}

bool StackEmpty(SequentialStack stack) {
    return stack.top == -1;
}

bool Push(SequentialStack &stack, Element data) {
    if (stack.top == MaxSize - 1) {
        return false;
    }
    stack.data[++stack.top] = data;
    return true;
}

bool Pop(SequentialStack &stack, Element &data) {
    if(stack.top == -1) {
        return false;
    }
    data = stack.data[stack.top--];
    return true;
}

bool GetTop(SequentialStack stack, Element &data) {
    if(stack.top == -1) {
        return false;
    }
    data = stack.data[stack.top];
    return true;
}

//****************************基本操作结束******************************