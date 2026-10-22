/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: 
There is no common prefix among the input strings.
*/

#include <stdlib.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int resultLength = 0;
    bool loop = true;

    while (strs[0][resultLength] != '\0') {
        char current = strs[0][resultLength];

        for (int i = 1; i < strsSize; i++) {
            if (strs[i][resultLength] != current) {
                loop = false;
                break;
            }
        }

        if (!loop) break;
        resultLength++;
    }

    char* result = malloc((resultLength + 1) * sizeof(char));
    if (!result) return NULL;
    for (size_t i = 0; i < resultLength; i++) result[i] = strs[0][i];
    result[resultLength] = '\0';
    return result;
}