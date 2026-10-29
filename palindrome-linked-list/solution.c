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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        struct ListNode* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* p1 = head;
    struct ListNode* p2 = reverseList(slow->next);

    while (p2 != NULL) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}