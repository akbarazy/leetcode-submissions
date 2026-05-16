/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 
3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2
Input: root = [1,2]
Output: 1
*/

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int depth(struct TreeNode *root, int *diameter) {
    if(root == NULL)
        return 0;

    int leftDepth = depth(root->left, diameter);
    int rightDepth = depth(root->right, diameter);
    *diameter = max(*diameter, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(struct TreeNode *root) {
    int diameter = 0;
    depth(root, &diameter);
    return diameter;
}