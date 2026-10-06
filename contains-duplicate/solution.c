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

int hash(int key) {
    int hash = key % TABLE_SIZE;
    return hash < 0 ? hash + TABLE_SIZE : hash;
}

struct HashMap* createMap() {
    struct HashMap* map = (struct HashMap*) malloc(sizeof(struct HashMap));
    for (int i = 0; i < TABLE_SIZE; i++) map->buckets[i] = NULL;    
    return map;
}

bool find(struct HashMap* map, int key) {
    struct Node* currentNode = map->buckets[hash(key)];
    
    while (currentNode != NULL) {
        if (currentNode->key == key) return true;
        currentNode = currentNode->next;
    }

    return false;
}

bool insert(struct HashMap* map, int key, int value) {
    if (find(map, key)) return false;
    unsigned int index = hash(key);
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
    return true;
}

bool containsDuplicate(int* nums, int numsSize) {
    struct HashMap* saveNumber = createMap();

    for (int i = 0; i < numsSize; i++) {
        if (!insert(saveNumber, nums[i], nums[i])) return true;
    }

    return false;
}