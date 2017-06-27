/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool flag = true;  // true: from left to right    false: from right to left
        deque<TreeNode*> qLevel;
        if (root == nullptr) return result;
        qLevel.push_back(root);
        while (!qLevel.empty()) {
            deque<TreeNode*> temp;
            vector<int> vec;
            if (flag) {
                while (!qLevel.empty()) {
                    vec.push_back(qLevel.front() -> val);
                    if (qLevel.front() -> left)
                        temp.push_back(qLevel.front() -> left);
                    if (qLevel.front() -> right)
                        temp.push_back(qLevel.front() -> right);
                    qLevel.pop_front();
                }
            }
            else {
                while (!qLevel.empty()) {
                    vec.push_back(qLevel.back() -> val);
                    if (qLevel.back() -> right)
                        temp.push_front(qLevel.back() -> right);
                    if (qLevel.back() -> left)
                        temp.push_front(qLevel.back() -> left);
                    qLevel.pop_back();
                }
            }
            flag = !flag;
            result.push_back(vec);
            qLevel = temp;
        }
        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bool flag = true;  // true: from left to right    false: from right to left
        queue<TreeNode*> qLevel;
        if (root == nullptr) return result;
        qLevel.push(root);
        while (!qLevel.empty()) {
            int size = qLevel.size();
            vector<int> vec(size);
            for (int i = 0; i < size; ++i) {
                int j = (flag) ? i : (size - 1 - i);
                vec[j] = qLevel.front() -> val;
                if (qLevel.front() -> left)
                    qLevel.push(qLevel.front() -> left);
                if (qLevel.front() -> right)
                    qLevel.push(qLevel.front() -> right);
                qLevel.pop();
            }
            result.push_back(vec);
            flag = !flag;
        }
        return result;
    }
};
