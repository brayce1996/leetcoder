// Runtime: 4 ms, faster than 83.96% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

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
        queue<TreeNode*> currQueue;
        if (root) currQueue.push(root);
        
        bool leftToRight = true;
        
        while (!currQueue.empty()) {
            int size = currQueue.size();
            vector<int> levelNodes(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = currQueue.front();
                currQueue.pop();
                
                int index = (leftToRight)? i : size - i - 1 ;
                levelNodes[index] = curr->val;
                
                if (curr->left) currQueue.push(curr->left);
                if (curr->right) currQueue.push(curr->right);
                
            }
            
            ans.push_back(levelNodes);
            leftToRight = !leftToRight;
        }
        
        return ans;
    }
};
