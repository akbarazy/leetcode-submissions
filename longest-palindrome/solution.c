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

#include <string.h>
#include <stdbool.h>

int longestPalindrome(char* s){
    int letterCount[52] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            letterCount[s[i] - 'a']++;
        } else {
            letterCount[s[i] - 'A' + 26]++;
        }
    }
    
    int length = 0;
    bool hasOdd = false;

    for (int i = 0; i < 52; i++) {
        length += (letterCount[i] / 2) * 2;

        if (letterCount[i] % 2) {
            hasOdd = true;
        }
    }

    if (hasOdd) {
        length++;
    }
    
    return length;
}