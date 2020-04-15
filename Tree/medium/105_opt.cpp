// Runtime: 12 ms, faster than 98.12% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 17.4 MB, less than 42.86% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// reference: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map

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
    int inIdx = 0;
    int preIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return split(preorder, inorder, INT_MIN);
    }
    
    TreeNode* split(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (preIdx == preorder.size()) return NULL;
        if (inorder[inIdx] == stop) {
            inIdx++;
            return NULL;
        }
        
        TreeNode* curr = new TreeNode(preorder[preIdx]);
        preIdx++;
        curr->left = split(preorder, inorder, curr->val);
        curr->right = split(preorder, inorder, stop);
        
        return curr;
    }
};
