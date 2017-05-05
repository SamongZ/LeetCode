/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        ListNode *p = nullptr;
        int a = 0;
        int sum = 0;
        while (l1 || l2 || a) {
            if (l1 && l2)
                sum = l1->val + l2->val + a;
            else if (!l1 && l2)
                sum = l2->val + a;
            else if (!l2 && l1)
                sum = l1->val + a;
            else if (a)
                sum = a;
            a = sum / 10;
            if (!result)
                result = p = new ListNode(sum % 10);
            else {
                p->next = new ListNode(sum % 10);
                p = p->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return result;
    }
};
