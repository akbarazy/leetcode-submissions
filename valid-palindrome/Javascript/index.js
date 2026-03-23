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

var isPalindrome = function(s) {
    let index = 0, length = s.length;
    let str = new Array(length + 1);

    for(let i = 0; i < s.length; i++) {
        let c = s[i];

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            str[index++] = (c >= 'A' && c <= 'Z') 
                ? String.fromCharCode(c.charCodeAt(0) + 32) 
                : c;
        } else {
            length--;
        }
    }

    str[index] = '\0';
    index = length - 1;

    for(let i = 0; i < Math.floor(length / 2); i++) {
        if(str[i] !== str[index - i]) return false;
    }

    return true;
};