/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ? k ? BST's total elements.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        nodeOrder(root, order);
        return order[k - 1];
    }
private:
    void nodeOrder(TreeNode* p, vector<int> &order) {
        if (p == nullptr) return;
        nodeOrder(p -> left, order);
        order.push_back(p -> val);
        nodeOrder(p -> right, order);
    }
};
