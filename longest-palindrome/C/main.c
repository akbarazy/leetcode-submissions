/*
Given a string s which consists of lowercase or uppercase letters, 
return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1
Input: s = "abccccdd"
Output: 7
Explanation: 
One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2
Input: s = "a"
Output: 1
Explanation: 
The longest palindrome that can be built is "a", whose length is 1.
*/

#include <stdio.h>
#include <string.h>

int longestPalindrome(char * s){
    int freq[128] = {0};

    for(int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    int length = 0;
    int hasOdd = 0;

    for(int i = 0; i < 128; i++) {
        if(freq[i] % 2 == 0) {
            length += freq[i];
        } else {
            length += freq[i] - 1;
            hasOdd = 1;
        }
    }

    if(hasOdd) length++;

    return length;
}