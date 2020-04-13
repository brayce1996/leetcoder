// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 11.6 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

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
        if (root) currStack.push(root);

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

            levelNodes.push_back(curr->val);
            if (leftToRight) {
                if (curr->left) nextStack.push(curr->left);
                if (curr->right) nextStack.push(curr->right);
            } else {
                if (curr->right) nextStack.push(curr->right);
                if (curr->left) nextStack.push(curr->left);
            }
            
        }
        
        if (!levelNodes.empty()) ans.push_back(levelNodes);

        return ans;
    }
};
