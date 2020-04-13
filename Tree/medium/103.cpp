// Runtime: 8 ms, faster than 26.86% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 11.4 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> currStack;
        stack<TreeNode*> nextStack;
        currStack.push(root);
        
        int currLevelCount = 0;
        int currLevelLimit = 1;
        int currNullCount = 0;
        vector<int> levelNodes;
        bool leftToRight = true;
        
        while (!nextStack.empty() || !currStack.empty()) {
            if (currStack.empty()) {
                ans.push_back(levelNodes);
                levelNodes.clear();
                leftToRight = !leftToRight;
                currStack = nextStack;
                stack<TreeNode*> ().swap(nextStack); // clear
            }
            
            TreeNode* curr = currStack.top();
            currStack.pop();
            
            if (curr != NULL) {
                levelNodes.push_back(curr->val);
                if (leftToRight) {
                    nextStack.push(curr->left);
                    nextStack.push(curr->right);
                } else {
                    nextStack.push(curr->right);
                    nextStack.push(curr->left);
                }
            }
        }
        
        return ans;
    }
};
