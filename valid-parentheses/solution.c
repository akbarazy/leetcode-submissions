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

void push(struct Node** peek, char value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    if (!node) {
        return;
    }

    node->data = value;
    node->next = *peek;
    *peek = node;
}

void pop(struct Node** peek) {
    if (!*peek) {
        return;
    }

    struct Node* temp = *peek;
    *peek = (*peek)->next;
    free(temp);
}

bool empty(struct Node* peek) {
    return !peek;
}

bool isValid(char* s) {
    struct Node* peek = NULL;

    while (*s != '\0') {
        if (
            *s == '(' ||
            *s == '{' ||
            *s == '['
        ) {
            push(&peek, *s);
        } else {
            if (empty(peek)) {
                return false;
            }

            char current = peek->data;
            pop(&peek);

            if (
                (current == '(' && *s != ')') ||
                (current == '{' && *s != '}') ||
                (current == '[' && *s != ']')
            ) {
                return false;
            }
        }

        s++;
    }

    return empty(peek);
}