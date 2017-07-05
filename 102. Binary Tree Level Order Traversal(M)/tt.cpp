/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            queue<TreeNode*> temp;
            while (!q.empty()) {
                vec.push_back(q.front() -> val);
                if (q.front() -> left)
                    temp.push(q.front() -> left);
                if (q.front() -> right)
                    temp.push(q.front() -> right);
                q.pop();
            }
            q = temp;
            result.push_back(vec);
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> qLevel;
        if (root == nullptr) return result;
        qLevel.push(root);
        while (!qLevel.empty()) {
            int size = qLevel.size();
            vector<int> vec(size);
            for (int i = 0; i < size; ++i) {
                vec[i] = qLevel.front() -> val;
                if (qLevel.front() -> left)
                    qLevel.push(qLevel.front() -> left);
                if (qLevel.front() -> right)
                    qLevel.push(qLevel.front() -> right);
                qLevel.pop();
            }
            result.push_back(vec);
        }
        return result;
    }
};
