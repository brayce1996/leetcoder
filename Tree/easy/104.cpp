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
        return recursive(root, 0);
    }
    
    int recursive(TreeNode* curr, int depth) {
        if (curr == NULL) {
            return depth;
        }
        int left = recursive(curr->left, depth + 1);
        int right = recursive(curr->right, depth + 1);
        return max(left, right);
    }
};
