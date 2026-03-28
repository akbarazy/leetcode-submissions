/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a 
normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
- void push(int x) Pushes element x to the back of the queue.
- int pop() Removes the element from the front of the queue and returns it.
- int peek() Returns the element at the front of the queue.
- boolean empty() Returns true if the queue is empty, false otherwise.
Notes:
- You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1
Input: 
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
Output: [null, null, null, 1, 1, false]
Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int top;
} MyStack;

void initMyStack(MyStack *s, int size) {
    s->data = (int*)malloc(sizeof(int) * size);
    s->top = -1;
}

void myStackPush(MyStack *s, int x) {
    s->data[++(s->top)] = x;
}

int myStackPop(MyStack *s) {
    return s->data[(s->top)--];
}

int myStackPeek(MyStack *s) {
    return s->data[s->top];
}

bool myStackEmpty(MyStack *s) {
    return s->top == -1;
}

typedef struct {
    MyStack inStack;
    MyStack outStack;
} MyQueue;

MyQueue *myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    initMyStack(&q->inStack, 1000);
    initMyStack(&q->outStack, 1000);
    return q;
}

void myQueuePush(MyQueue *q, int x) {
    myStackPush(&q->inStack, x);
}

int myQueuePop(MyQueue *q) {
    if (myStackEmpty(&q->outStack)) {
        while (!myStackEmpty(&q->inStack)) {
            myStackPush(&q->outStack, myStackPop(&q->inStack));
        }
    }
    return myStackPop(&q->outStack);
}

int myQueuePeek(MyQueue *q) {
    if (myStackEmpty(&q->outStack)) {
        while (!myStackEmpty(&q->inStack)) {
            myStackPush(&q->outStack, myStackPop(&q->inStack));
        }
    }
    return myStackPeek(&q->outStack);
}

bool myQueueEmpty(MyQueue *q) {
    return myStackEmpty(&q->inStack) && myStackEmpty(&q->outStack);
}

void myQueueFree(MyQueue *q) {
    free(q->inStack.data);
    free(q->outStack.data);
    free(q);
}