/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
It reads the same forward and backward, alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: 
String "amanaplanacanalpanama" is a palindrome.

Example 2
Input: s = "race a car"
Output: false
Explanation: 
String "raceacar" is not a palindrome.

Example 3
Input: s = " "
Output: true
Explanation: 
When its an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s) {
    int index = 0, length = strlen(s);
    char string[length + 1];

    while(*s) {
        if((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122)) {
            string[index++] = (*s >= 65 && *s <= 90) ? *s + 32 : *s;
        } else {
            length--;
        }

        s++;
    }

    string[index] = '\0';
    index = length - 1;

    for(int i = 0; i < (length / 2); i++) {
        if(string[i] != string[index - i]) return false;
    }

    return true;
}