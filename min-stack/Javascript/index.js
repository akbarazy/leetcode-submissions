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

var MinStack = function() {
    this.stack = [];
};

MinStack.prototype.push = function(value) {
    if (this.stack.length === 0) {
        this.stack.push({ val: value, min: value });
    } else {
        const currentMin = this.stack[this.stack.length - 1].min;
        this.stack.push({
            val: value,
            min: Math.min(value, currentMin)
        });
    }
};

MinStack.prototype.pop = function() {
    if (this.stack.length > 0) {
        this.stack.pop();
    }
};

MinStack.prototype.top = function() {
    return this.stack[this.stack.length - 1].val;
};

MinStack.prototype.getMin = function() {
    return this.stack[this.stack.length - 1].min;
};