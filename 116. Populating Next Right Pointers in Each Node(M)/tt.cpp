/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node,
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution1 {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<TreeLinkNode*> level(size);
            for (int i = 0; i < size; ++i) {
                level[i] = q.front();
                if (q.front() -> left) q.push(q.front() -> left);
                if (q.front() -> right) q.push(q.front() -> right);
                q.pop();
            }
            for (int j = 0; j < level.size() - 1; ++j)
                level[j] -> next = level[j + 1];
        }
    }
};

class Solution2 {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *pre = root;
        TreeLinkNode *curr = nullptr;
        while (pre -> left) {
            curr = pre;
            while (curr) {
                curr -> left -> next = curr -> right;
                if (curr -> next)
                    curr -> right -> next = curr -> next ->left;
                curr = curr -> next;
            }
            pre = pre -> left;
        }
    }
};
