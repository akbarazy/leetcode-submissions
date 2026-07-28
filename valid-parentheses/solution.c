/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example 1
Input: s = "()"
Output: true

Example 2
Input: s = "()[]{}"
Output: true

Example 3
Input: s = "(]"
Output: false

Example 4
Input: s = "([])"
Output: true

Example 5
Input: s = "([)]"
Output: false
*/

#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) exit(1);

    node->data = data;
    node->next = NULL;
    return node;
}

bool isEmpty(struct Node* top) {
    return top == NULL;
}

void push(struct Node** top, char data) {
    struct Node* node = createNode(data);
    node->next = *top;
    *top = node;
}

char pop(struct Node** top) {
    struct Node* temp = *top;
    char data = temp->data;

    *top = (*top)->next;
    free(temp);
    return data;
}

bool isValid(char *s) {
    struct Node* openBrackets = NULL;

    while(*s != '\0') {
        if (
            *s == '(' ||
            *s == '[' ||
            *s == '{'
        ) {
            push(&openBrackets, *s);
        } else {
            if (isEmpty(openBrackets)) return false;
            char openBracket = pop(&openBrackets);

            if (
                (*s == ')' && openBracket != '(') ||
                (*s == ']' && openBracket != '[') ||
                (*s == '}' && openBracket != '{')
            ) {
                return false;
            }
        }
        s++;
    }

    return isEmpty(openBrackets);
}