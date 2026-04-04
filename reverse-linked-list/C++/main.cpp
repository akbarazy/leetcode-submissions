/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2
Input: head = [1,2]
Output: [2,1]

Example 3
Input: head = []
Output: []
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while(curr != nullptr) {
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    return prev;
}