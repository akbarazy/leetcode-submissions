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

#include <string.h>
#include <ctype.h>

bool isPalindrome(char *s) {
    int left = 0, 
        right = strlen(s) - 1;

    while (left < right) {
        while (
            left < right && 
            !isalnum((unsigned char)s[left])) {
            left++;
        } 
        
        while (
            left < right && 
            !isalnum((unsigned char)s[right])) {
            right--;
        } 
        
        if (
            tolower((unsigned char)s[left]) != 
            tolower((unsigned char)s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}