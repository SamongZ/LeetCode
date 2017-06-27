/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> qLevel;
        qLevel.push(root);
        int depth = 0;
        while (!qLevel.empty()) {
            int size = qLevel.size();
            for (int i = 0; i < size; ++i) {
                if (qLevel.front() -> left)
                    qLevel.push(qLevel.front() -> left);
                if (qLevel.front() -> right)
                    qLevel.push(qLevel.front() -> right);
                qLevel.pop();
            }
            ++depth;
        }
        return depth;
    }
};
