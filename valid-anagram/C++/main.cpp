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

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    int count[2][26] = {0};

    int i = 0;
    while(i < s.size() && i < t.size()) {
        count[0][s[i] - 'a']++;
        count[1][t[i] - 'a']++;
        i++;
    }

    if(s.size() != t.size()) return false;

    for(int j = 0; j < 26; j++) {
        if (count[0][j] != count[1][j]) return false;
    }

    return true;
}