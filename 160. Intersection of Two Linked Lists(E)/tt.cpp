/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J
B:     b1 �� b2 �� b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *p = headA, *q = headB;
        while (p != nullptr) {
            ++len1;
            p = p -> next;
        }
        while (q != nullptr) {
            ++len2;
            q = q -> next;
        }
        p = headA;
        q = headB;
        if (len1 > len2)
            for (int i  = 0; i < len1 - len2; ++i)
                p = p -> next;
        else
            for (int i = 0; i < len2 - len1; ++i)
                q = q -> next;
        while (p != q) {
            p = p -> next;
            q = q -> next;
        }
        return p;
    }
};
