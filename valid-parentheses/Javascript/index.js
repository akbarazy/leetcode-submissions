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

var isValid = function(s) {
    let stack = [];

    for(let c of s) {
        if(c === '(' || c === '[' || c === '{') {
            stack.push(c);
        } else {
            if(stack.length < 1) return false;

            let openBracket = stack.pop();

            if(
                (openBracket === '(' && c !== ')') ||
                (openBracket === '[' && c !== ']') ||
                (openBracket === '{' && c !== '}')
            ) {
                return false;
            }
        }
    }

    return stack.length === 0;
}