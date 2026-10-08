/*
Given two binary strings a and b, return their sum as a binary string.

Example 1
Input: 
    a = "11"
    b = "1"
Output: "100"

Example 2
Input: 
    a = "1010"
    b = "1011"
Output: "10101"
*/

#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);

    int indexA = lenA - 1;
    int indexB = lenB - 1;
    int digit = 0;
    int carry = 0;

    int maxLen = (lenA > lenB ? lenA : lenB) + 2;
    char* result = (char*)calloc(maxLen, sizeof(char));

    while (indexA >= 0 || indexB >= 0 || carry) {
        int sum = carry;

        if (indexA >= 0) {
            sum += a[indexA] - '0';
            indexA--;
        }

        if (indexB >= 0) {
            sum += b[indexB] - '0';
            indexB--;
        }

        carry = sum / 2;
        result[digit++] = (sum % 2) + '0';
    }

    for (int left = 0, right = digit - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    
    return result;
}