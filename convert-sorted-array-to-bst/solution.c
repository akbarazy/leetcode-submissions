/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: 
[0,-10,5,null,-3,null,9] is also accepted.

Example 2
Input: nums = [1,3]
Output: [3,1]
Explanation: 
[1,null,3] and [3,1] are both height-balanced BSTs.
*/

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL)
        return NULL; 
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildBST(int* nums, int left, int right) {
    if (left > right) 
        return NULL;
    int mid = (right + left) / 2;
    struct TreeNode* root = createNode(nums[mid]);
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildBST(nums, 0, numsSize - 1);
}