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

class TreeNode {
    constructor(val, left, right) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

function checkHeight(root) {
    if(root === null) return 0;

    let left = checkHeight(root.left);
    if(left === -1) return -1;

    let right = checkHeight(root.right);
    if(right === -1) return -1;

    if(Math.abs(left - right) > 1) return -1;

    return Math.max(left, right) + 1;
}

function isBalanced(root) {
    return checkHeight(root) !== -1;
}