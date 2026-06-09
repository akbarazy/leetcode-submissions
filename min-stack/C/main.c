/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
- MinStack() initializes the stack object.
- void push(int value) pushes the element value onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1
Input:
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]
Output: [null,null,null,null,-3,null,0,-2]
Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int val;
    int min;
} Node;

typedef struct {
    Node* data;
    int top_idx;
    int capacity;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = 1000;
    obj->data = (Node*)malloc(obj->capacity * sizeof(Node));
    obj->top_idx = -1;
    return obj;
}

void minStackPush(MinStack* obj, int value) {
    if (obj->top_idx == obj->capacity - 1) {
        obj->capacity *= 2;
        obj->data = (Node*)realloc(obj->data, obj->capacity * sizeof(Node));
    }
    
    obj->top_idx++;
    obj->data[obj->top_idx].val = value;
    
    if (obj->top_idx == 0) {
        obj->data[obj->top_idx].min = value;
    } else {
        int prev_min = obj->data[obj->top_idx - 1].min;
        obj->data[obj->top_idx].min = (value < prev_min) ? value : prev_min;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top_idx >= 0) {
        obj->top_idx--;
    }
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top_idx].val;
}

int minStackGetMin(MinStack* obj) {
    return obj->data[obj->top_idx].min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    free(obj);
}