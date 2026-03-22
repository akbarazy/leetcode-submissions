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

#include <stdio.h>

bool isAnagram(char *s, char *t) {
    int count[2][26];

    while(*s) {
        count[0][*s - 'a']++;
        count[1][*t - 'a']++;

        s++;
        t++;
    }

    for(int i = 0; i < 26; i++) {
        if(count[0][i] != count[1][i]) return false;
    }

    return true;
}