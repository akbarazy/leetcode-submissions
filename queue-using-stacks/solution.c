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

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int top;
} MyStack;

typedef struct {
    MyStack in;
    MyStack out;
} MyQueue;

void myStackInit(MyStack* stack, int size) {
    stack->data = (int*)malloc(sizeof(int) * size);
    stack->top = -1;
}

void myStackPush(MyStack* stack, int data) {
    stack->data[++(stack->top)] = data;
}

int myStackPop(MyStack* stack) {
    return stack->data[(stack->top)--];
}

bool myStackEmpty(MyStack* stack) {
    return stack->top == -1;
}

void myStackMove(MyQueue* queue) {
    if (myStackEmpty(&queue->out)) {
        while (!myStackEmpty(&queue->in)) {
            myStackPush(&queue->out, myStackPop(&queue->in));
        }
    }
}

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    myStackInit(&queue->in, 1000);
    myStackInit(&queue->out, 1000);
    return queue;
}

void myQueuePush(MyQueue* queue, int x) {
    myStackPush(&queue->in, x);
}

int myQueuePop(MyQueue* queue) {
    myQueueMove(queue);
    return myStackPop(&queue->out);
}

int myQueuePeek(MyQueue* queue) {
    myQueueMove(queue);
    return queue->out.data[queue->out.top];
}

bool myQueueEmpty(MyQueue* queue) {
    return myStackEmpty(&queue->in) && myStackEmpty(&queue->out);
}

void myQueueFree(MyQueue* queue) {
    free(queue->in.data);
    free(queue->out.data);
    free(queue);
}