/*
Reverse a singly linked list.
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        stack<ListNode*> node;
        while (head) {
            node.push(head);
            head = head -> next;
        }
        ListNode *newHead = node.top();
        while (node.size() != 1) {
            ListNode *p = node.top();
            node.pop();
            p -> next = node.top();
        }
        node.top() -> next = nullptr;
        return newHead;
    }
};
