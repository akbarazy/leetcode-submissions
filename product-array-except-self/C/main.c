/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int prefix = 1;
    
    for (int i = 0; i < numsSize; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}