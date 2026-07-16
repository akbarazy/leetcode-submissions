/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1
Input: 
    nums = [2, 7, 11, 15]
    target = 9
Output: [0, 1]
Explanation: 
Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2
Input: 
    nums = [3,2,4]
    target = 6
Output: [1,2]

Example 3
Input: 
    nums = [3,3]
    target = 6
Output: [0,1]
*/

#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct HashMap {
    struct Node* buckets[TABLE_SIZE];
};

int hashFunction(int key) {
    int hash = key % TABLE_SIZE;
    return hash < 0 ? hash + TABLE_SIZE : hash;
}

struct HashMap* createMap() {
    struct HashMap* map = (struct HashMap*) malloc(sizeof(struct HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

void insert(struct HashMap* map, int key, int value) {
    unsigned int index = hashFunction(key);

    struct Node* currentNode = map->buckets[index];
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            currentNode->value = value;
            return;
        }
        currentNode = currentNode->next;
    }
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct HashMap* numberIndex = createMap();
    int* result = (int*) malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int currentNumber = nums[i];
        int complement = target - currentNumber;
        
        struct Node* currentNode = numberIndex->buckets[hashFunction(complement)];
        while (currentNode != NULL) {
            if (currentNode->key == complement) {
                result[0] = currentNode->value;
                result[1] = i;

                *returnSize = 2;
                return result;
            }
            currentNode = currentNode->next;
        }
        
        insert(numberIndex, currentNumber, i);
    }

    *returnSize = 0;
    return NULL;
}