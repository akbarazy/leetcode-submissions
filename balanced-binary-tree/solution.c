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

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int checkHeight(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = checkHeight(root->left);
    if (left == -1) return -1;

    int right = checkHeight(root->right);
    if (right == -1) return -1;

    int diff = left - right;
    if (((diff < 0) ? -diff : diff) > 1) return -1;

    return ((left > right) ? left : right) + 1;
}

int isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;
}