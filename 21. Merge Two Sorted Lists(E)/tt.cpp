/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *pNewHead = nullptr;
        ListNode *pCurr = nullptr;
        while (l1 && l2) {
            if (l1 -> val >= l2 -> val) {
                if (pNewHead == nullptr) {
                    pNewHead = pCurr = l2;
                }
                else {
                    pCurr -> next = l2;
                    pCurr = l2;
                }
                l2 = l2 -> next;
            }
            else {
                if (pNewHead == nullptr) {
                    pNewHead = pCurr = l1;
                }
                else {
                    pCurr -> next = l1;
                    pCurr = l1;
                }
                l1 = l1 -> next;
            }
        }
        pCurr -> next = l1 ? l1 : l2;
        return pNewHead;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *pNewHead = nullptr;
        if (l1 -> val >= l2 -> val) {
            pNewHead = l2;
            pNewHead -> next = mergeTwoLists(l1, l2 -> next);
        }
        else {
            pNewHead = l1;
            pNewHead -> next = mergeTwoLists(l1 -> next, l2);
        }
        return pNewHead;
    }
};
