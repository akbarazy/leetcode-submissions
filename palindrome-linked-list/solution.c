/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1
Input: head = [1,2,2,1]
Output: true

Example 2
Input: head = [1,2]
Output: false
*/

#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
        if (fast != NULL) fast = fast->next;
    }

    struct ListNode* linkedList1 = head;
    struct ListNode* linkedList2 = NULL;
    struct ListNode* current = slow;
    
    while (current != NULL) {
        struct ListNode* next = current->next;
        current->next = linkedList2;
        linkedList2 = current;
        current = next;
    }

    while (linkedList2 != NULL) {
        if (linkedList1->val != linkedList2->val) return false;
        linkedList1 = linkedList1->next;
        linkedList2 = linkedList2->next;
    }

    return true;
}