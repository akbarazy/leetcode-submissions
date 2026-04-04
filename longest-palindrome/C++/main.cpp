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

#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freq;

    for(char c : s) {
        freq[c]++;
    }

    int length = 0;
    bool hasOdd = false;

    for(auto &pair : freq) {
        if(pair.second % 2 == 0) {
            length += pair.second;
        } else {
            length += pair.second - 1;
            hasOdd = true;
        }
    }

    if(hasOdd) length++;

    return length;
}