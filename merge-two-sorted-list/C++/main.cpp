/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1
Input: 
    list1 = [1,2,4]
    list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2
Input: 
    list1 = []
    list2 = []
Output: []

Example 3
Input: 
    list1 = []
    list2 = [0]
Output: [0]
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *node = new ListNode(0);
    ListNode *currentNode = node;

    while(list1 != nullptr && list2 != nullptr) {
        if(list1->val < list2->val) {
            currentNode->next = list1;
            list1 = list1->next;
        } else {
            currentNode->next = list2;
            list2 = list2->next;
        }

        currentNode = currentNode->next;
    }

    if(list1 != nullptr) {
        currentNode->next = list1;
    } else if(list2 != nullptr) {
        currentNode->next = list2;
    }

    return node->next;
}