/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1
Input: 
    s = "anagram" 
    t = "nagaram"
Output: true

Example 2
Input: 
    s = "rat"
    t = "car"
Output: false
*/

#include <string.h>

bool isAnagram(char* s, char* t) {
    int numberEachLetter[26] = {0};
    int length = strlen(s);

    if (length != strlen(t)) return false;

    for (int i = 0; i < length; i++) {
        int indexS = s[i] - 'a';
        numberEachLetter[indexS]++;

        int indexT = t[i] - 'a';
        numberEachLetter[indexT]--;
    }

    for(int i = 0; i < 26; i++) {
        if(numberEachLetter[i] != 0) return false;
    }

    return true;
}