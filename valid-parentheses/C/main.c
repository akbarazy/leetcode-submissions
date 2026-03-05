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

#include <stdio.h>
#include <stdbool.h>

bool isValid(char *s) {
    int length = strlen(s);
    int back = -1;
    char *s1 = s;
    
    while(*s) {
        char *s2 = s;

        if(*s == ')' || *s == ']' || *s == '}') {
            back += 2;
            if(s2 > s1) s2 -= back;

            if(
                (*s2 != '(' && *s == ')') ||
                (*s2 != '[' && *s == ']') ||
                (*s2 != '{' && *s == '}')
            ) {
                return false;
            }
        } else {
            if(back > -1) back = -1;
        }

        s++;
    }

    return true;
}