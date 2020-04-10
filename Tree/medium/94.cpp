// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (root == NULL) return inorder;
        stack<TreeNode*> frame;
        frame.push(root);
        while (!frame.empty()) {
            TreeNode* currRoot = frame.top();
            
            if (currRoot->left != NULL) {
                frame.push(currRoot->left);
                currRoot->left = NULL;
            } else {
                frame.pop(); // pop currRoot
                inorder.push_back(currRoot->val);
                
                if (currRoot->right != NULL) {
                    frame.push(currRoot->right);
                    currRoot->right = NULL;
                }
            }
        }
        return inorder;
    }
};