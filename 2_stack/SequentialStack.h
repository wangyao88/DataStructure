#ifndef DEMO_SEQUENTIALSTACK_H
#define DEMO_SEQUENTIALSTACK_H

#define MaxSize 50

typedef int Element;

typedef struct SequentialStack {
    Element data[MaxSize];
    int top;
} SequentialStack;

//****************************基本操作开始******************************

/**
 * 初始化栈
 * @param stack
 */
void InitStack(SequentialStack &stack);

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
bool StackEmpty(SequentialStack stack);

/**
 * 进栈
 * @param stack
 * @param data
 * @return
 */
bool Push(SequentialStack &stack, Element data);

/**
 * 出栈
 * @param stack
 * @param data
 * @return
 */
bool Pop(SequentialStack &stack, Element &data);

/**
 * 获取栈顶元素值
 * @param stack
 * @param data
 * @return
 */
bool GetTop(SequentialStack stack, Element &data);

/**
 * 销毁栈
 * @param stack
 */
void DestroyStack(SequentialStack stack);

//****************************基本操作结束******************************

#endif //DEMO_SEQUENTIALSTACK_H
