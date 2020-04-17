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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> frame;
        frame.push(root);
        int counter = 0;
        int currVal = 0;
        TreeNode* curr = root;
        while (!frame.empty()) {
            while (curr) {
                frame.push(curr);
                curr = curr->left;
            }
            curr = frame.top();
            frame.pop();
            counter++;
            if (counter == k) return curr->val;
            curr = curr->right;
        }
        return 0;
    }
};
