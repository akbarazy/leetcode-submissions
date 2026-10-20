/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Do not solve it with built-in functions (i.e., like __builtin_popcount in C++).

Example 1
Input: n = 2
Output: [0, 1, 1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    if (result == NULL) return NULL;
    result[0] = 0;
    for (size_t i = 1; i <= n; i++) result[i] = result[i >> 1] + (i & 1);
    return result;
}