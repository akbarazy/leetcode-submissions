/*
Given two binary strings a and b, return their sum as a binary string.

Example 1
Input: 
    a = "11"
    b = "1"
Output: "100"
Example 2:

Input: 
    a = "1010"
    b = "1011"
Output: "10101"
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB ? lenA : lenB) + 2;
    char* result = (char*)malloc(maxLen * sizeof(char));

    int i = lenA - 1;
    int j = lenB - 1;
    int k = 0;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if(i >= 0) {
            sum += a[i] - '0';
            i--;
        }

        if(j >= 0) {
            sum += b[j] - '0';
            j--;
        }

        result[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[k] = '\0';

    for(int l = 0, r = k - 1; l < r; l++, r--) {
        char temp = result[l];
        result[l] = result[r];
        result[r] = temp;
    }

    return result;
}