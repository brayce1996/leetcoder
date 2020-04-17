// Runtime: 8 ms, faster than 87.93% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 17 MB, less than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.

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
        queue<TreeNode*> que;
        if (root) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            depth++;
            for (int i = 0, limit = que.size(); i < limit; i++) {
                TreeNode* curr = que.front();
                que.pop();
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
        }
        return depth;
    }
};
