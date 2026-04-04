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

var longestPalindrome = function(s) {
    const freq = {};

    for(let c of s) {
        freq[c] = (freq[c] || 0) + 1;
    }

    let length = 0;
    let hasOdd = false;

    for(let key in freq) {
        if(freq[key] % 2 === 0) {
            length += freq[key];
        } else {
            length += freq[key] - 1;
            hasOdd = true;
        }
    }

    if(hasOdd) length++;

    return length;
};