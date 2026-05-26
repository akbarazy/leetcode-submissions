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

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct {
    int** data;
    int* colSizes;
    int size;
    int capacity;
} Result;

void addLevel(Result* res, int* level, int levelSize) {
    if (res->size >= res->capacity) {
        res->capacity *= 2;
        res->data = realloc(res->data, sizeof(int*) * res->capacity);
        res->colSizes = realloc(res->colSizes, sizeof(int) * res->capacity);
    }

    res->data[res->size] = level;
    res->colSizes[res->size] = levelSize;
    res->size++;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (root == NULL) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    Result res;
    res.size = 0;
    res.capacity = 10;
    res.data = malloc(sizeof(int*) * res.capacity);
    res.colSizes = malloc(sizeof(int) * res.capacity);

    struct TreeNode** queue = malloc(sizeof(struct TreeNode*) * 2000);

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        int* level = malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

            level[i] = node->val;

            if (node->left)
                queue[rear++] = node->left;

            if (node->right)
                queue[rear++] = node->right;
        }

        addLevel(&res, level, levelSize);
    }

    free(queue);

    *returnSize = res.size;
    *returnColumnSizes = res.colSizes;

    return res.data;
}