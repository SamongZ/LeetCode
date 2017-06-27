/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

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


class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        if (preorder.size() == 0)
            return root;
        root = new TreeNode(preorder[0]);
        int i = 0;
        while (inorder[i] != preorder[0]) ++i;
        vector<int> preLeft, inLeft, preRight, inRight;
        for (int j = 0; j < i; ++j) {
            preLeft.push_back(preorder[j + 1]);
            inLeft.push_back(inorder[j]);
        }
        for (int k = i + 1; k < preorder.size(); ++k) {
            preRight.push_back(preorder[k]);
            inRight.push_back(inorder[k]);
        }
        root -> left = buildTree(preLeft, inLeft);
        root -> right = buildTree(preRight, inRight);
        return root;
    }
};


class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return creat(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* creat(const vector<int>& preorder, int pb, int pe, const vector<int>& inorder, int ib, int ie) {
        if (pb > pe) return nullptr;
        TreeNode *root = new TreeNode(preorder[pb]);
        int i = ib;
        while (inorder[i] != preorder[pb] && i <= ie) ++i;
        root -> left = creat(preorder, pb + 1, pb + i - ib, inorder, ib, i - 1);
        root -> right = creat(preorder, pb + i - ib + 1, pe, inorder, i + 1, ie);
        return root;
    }
};
