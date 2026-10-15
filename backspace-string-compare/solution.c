/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1
Input:
    s = "ab#c"
    t = "ad#c"
Output: true
Explanation: 
Both s and t become "ac".

Example 2
Input:
    s = "ab##"
    t = "c#d#"
Output: true
Explanation: 
Both s and t become "".

Example 3
Input:
    s = "a#c"
    t = "b"
Output: false
Explanation: 
s becomes "c" while t becomes "b".
*/

#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int backspace;

    while (i >= 0 || j >= 0) {
        backspace = 0;

        while (i >= 0) {
            if (s[i] == '#') backspace++;
            else if (backspace > 0) backspace--;
            else break;
            i--;
        }
    
        backspace = 0;

        while (j >= 0) {
            if (t[j] == '#') backspace++;
            else if (backspace > 0) backspace--;
            else break;
            j--;
        }

        if (i < 0 && j < 0) return true;
        if (i < 0 || j < 0) return false;
        if (s[i] != t[j]) return false;
        i--;
        j--;
    }

    return true;
}