/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return creat(nums, 0, nums.size() - 1);
    }
    TreeNode* creat(vector<int> &nums, int beg, int end) {
        if (beg > end) return nullptr;
        int size = end - beg + 1;
        TreeNode *root = new TreeNode(nums[beg + size / 2]);
        root -> left = creat(nums, beg, beg + size / 2 - 1);
        root -> right = creat(nums, beg + size / 2 + 1, end);
        return root;
    }
};
