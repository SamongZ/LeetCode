/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
also the following example is not:
    1
   / \
  2   3
 /   /
3    2

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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> qleft;
        queue<TreeNode*> qright;
        qleft.push(root -> left);
        qright.push(root -> right);
        while (!qleft.empty() && !qright.empty()) {
            TreeNode *pl = qleft.front();
            TreeNode *pr = qright.front();
            qleft.pop();
            qright.pop();
            if (pl == nullptr && pr == nullptr)
                continue;
            if (pl == nullptr || pr == nullptr)
                return false;
            if (pl -> val !=  pr -> val)
                return false;
            qleft.push(pl -> left);
            qleft.push(pl -> right);
            qright.push(pr -> right);
            qright.push(pr -> left);
        }
        return true;
    }
};
