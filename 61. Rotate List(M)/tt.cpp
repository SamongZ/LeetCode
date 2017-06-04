/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *result;
        ListNode *p = head;
        if (head == nullptr) return head;
        int len = 1;
        for (; p -> next != nullptr; p = p -> next, ++len) { }
        p -> next = head;
        k = k % len;
        for (int i = 0; i < len - k; ++i)
            p = p -> next;
        result = p -> next;
        p -> next = nullptr;
        return result;
    }
};
