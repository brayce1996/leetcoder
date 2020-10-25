/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> xResult; // level, parent
    pair<int, int> yResult; // level, parent

    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;

        int parent = -1;
        dfs(root, parent, x, y, 0);

        if (xResult.first == yResult.first && xResult.second != yResult.second) {
            return true;
        }
        return false;
    }

    void dfs(TreeNode* curr, int parent, int x, int y, int level) {
        if (curr == NULL) return;

        if (curr->val == x) {
            xResult = pair<int, int>(level, parent);
        }

        if (curr->val == y) {
            yResult = pair<int, int>(level, parent);
        }

        dfs(curr->left, curr->val, x, y, level+1);
        dfs(curr->right, curr->val, x, y, level+1);
    }
};
