/*
Given a binary tree, determine if it is height-balanced.

Example 1
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3
Input: root = []
Output: true
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return(a > b) ? a : b;
}

int abs(int x) {
    return(x < 0) ? -x : x;
}

int checkHeight(struct TreeNode *root) {
    if(root == NULL) return 0;

    int left = checkHeight(root->left);
    if(left == -1) return -1;

    int right = checkHeight(root->right);
    if(right == -1) return -1;

    if(abs(left - right) > 1) return -1;

    return max(left, right) + 1;
}

int isBalanced(struct TreeNode *root) {
    return checkHeight(root) != -1;
}