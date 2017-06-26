/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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

 // Recursive solution
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        result = inorder(result, root);
        return result;
    }
    vector<int> inorder(vector<int> &vec, TreeNode *root) {
        if (root != nullptr) {
            inorder(vec, root -> left);
            vec.push_back(root -> val);
            inorder(vec, root -> right);
        }
        return vec;
    }
};
// iterative
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> temp;
        vector<int> result;
        TreeNode *pNode = root;
        while (!temp.empty() || pNode != nullptr) {
            if (pNode != nullptr) {
                temp.push(pNode);
                pNode = pNode -> left;
            }
            else {
                TreeNode *p = temp.top();
                result.push_back(p -> val);
                pNode = p -> right;
                temp.pop();
            }
        }
        return result;
    }
};
