/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2
Input: root = [1]
Output: [[1]]

Example 3
Input: root = []
Output: []
*/

class TreeNode {
    constructor(val, left, right) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

var levelOrder = function(root) {
    const result = [];

    if (root === null)
        return result;

    const queue = [root];

    while (queue.length > 0) {
        const levelSize = queue.length;
        const level = [];

        for (let i = 0; i < levelSize; i++) {
            const node = queue.shift();

            level.push(node.val);

            if (node.left !== null)
                queue.push(node.left);

            if (node.right !== null)
                queue.push(node.right);
        }

        result.push(level);
    }

    return result;
};