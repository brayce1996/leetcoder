// Runtime: 20 ms, faster than 76.80% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 17.6 MB, less than 42.86% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

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
    unordered_map<int, int> splitPoint;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        
        for (int i = 0; i < inorder.size(); i++) {
            splitPoint[inorder[i]] = i;
        }
        
        return split(preorder, 0, preorder.size(), inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* split(vector<int>& preorder, int preIndex, int preLimit, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd || preIndex >= preLimit) return NULL;
        TreeNode* currRoot = new TreeNode;
        currRoot->val = preorder[preIndex];
        
        int inMid = splitPoint[preorder[preIndex]];
        int leftCount = inMid - inStart;
        if (inStart < inMid) {
            currRoot->left = split(preorder, preIndex + 1, preIndex + leftCount + 1, inorder, inStart, inMid - 1);
        }
        
        if (inMid < inEnd) {
            currRoot->right = split(preorder, preIndex + leftCount + 1, preLimit, inorder, inMid + 1, inEnd);
        }
        return currRoot;
    }
};
