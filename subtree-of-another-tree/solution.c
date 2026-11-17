/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1
Input: 
    root = [3,4,5,1,2], 
    subRoot = [4,1,2]
Output: true

Example 2
Input: 
    root = [3,4,5,1,2,null,null,null,null,0], 
    subRoot = [4,1,2]
Output: false
*/

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    }

    if (root == NULL || subRoot == NULL) {
        return false;
    }

    if (root->val != subRoot->val) {
        return false;
    }

    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (subRoot == NULL) {
        return true;
    }

    if (root == NULL) {
        return false;
    }

    if (isSameTree(root, subRoot)) {
        return true;
    }
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}