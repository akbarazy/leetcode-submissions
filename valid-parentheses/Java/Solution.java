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

import java.util.ArrayDeque;
import java.util.Deque;

public class Solution {
    public boolean isValid(String s) {
        Deque<Character> openBrackets = new ArrayDeque<>();

        for (Character c : s.toCharArray()) {
            if (
                c == '(' ||
                c == '[' ||
                c == '{'
            ) {
                openBrackets.push(c);
            } else {
                if (openBrackets.isEmpty()) return false;
                Character openBracket = openBrackets.pop();

                if (
                    (c == ')' && openBracket != '(') ||
                    (c == ']' && openBracket != '[') ||
                    (c == '}' && openBracket != '{')
                ) {
                    return false;
                }
            }
        }

        return openBrackets.isEmpty();
    }
}