/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at indices 0 and 3.

Example 2
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <stdbool.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int left, int right) {
    int randomIndex = left + rand() % (right - left + 1);
    swap(&nums[randomIndex], &nums[right]);
    int pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (nums[j] == pivot) {
            return -1;
        } else if (nums[j] < pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[right]);
    return i + 1;
}

bool quickSort(int* nums, int left, int right) {
    if (left < right) {
        int pivot = partition(nums, left, right);

        if (pivot == -1) {
            return true;
        }

        bool leftSubarray = quickSort(nums, left, pivot - 1);

        if (leftSubarray) {
            return true;
        }

        return quickSort(nums, pivot + 1, right);
    }

    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }
    
    return quickSort(nums, 0, numsSize - 1);
}