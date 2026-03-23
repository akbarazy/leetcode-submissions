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

var isAnagram = function(s, t) {
    let count = Array.from({ length: 2 }, () => Array(26).fill(0));

    let i = 0;
    while(i < s.length && i < t.length) {
        count[0][s.charCodeAt(i) - 97]++;
        count[1][t.charCodeAt(i) - 97]++;
        i++;
    }

    if(s.length !== t.length) return false;

    for(let j = 0; j < 26; j++) {
        if(count[0][j] !== count[1][j]) return false;
    }

    return true;
}