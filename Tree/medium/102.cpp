// Runtime: 4 ms, faster than 93.58% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        int currLevelCount = 0; // limit = (level + 1) * 2
        int nullNodeCount = 0;
        int levelLimit = 1;
        vector<int> currLevelNodes;
        while (!bfsQueue.empty()) {
            if (currLevelCount == levelLimit) {
                levelLimit = (currLevelCount - nullNodeCount) * 2;
                currLevelCount = 0;
                nullNodeCount = 0;
                ans.push_back(currLevelNodes);
                currLevelNodes.clear();
            }
            TreeNode* curr = bfsQueue.front();
            bfsQueue.pop();
            if (curr != NULL) {
                currLevelNodes.push_back(curr->val);
                bfsQueue.push(curr->left);
                bfsQueue.push(curr->right);
            } else nullNodeCount++;
            currLevelCount++;
        }
        return ans;
    }
};
