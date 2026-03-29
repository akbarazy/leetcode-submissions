/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1
Input: 
    ransomNote = "a"
    magazine = "b"
Output: false

Example 2
Input: 
    ransomNote = "aa"
    magazine = "ab"
Output: false

Example 3
Input: 
    ransomNote = "aa"
    magazine = "aab"
Output: true
*/

var canConstruct = function(ransomNote, magazine) {
    const count = new Array(26).fill(0);

    for(let c of magazine) {
        count[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    for(let c of ransomNote) {
        let index = c.charCodeAt(0) - 'a'.charCodeAt(0);
        count[index]--;
        if(count[index] < 0) {
            return false;
        }
    }

    return true;
};