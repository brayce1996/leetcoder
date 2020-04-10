// Runtime: 16 ms, faster than 55.22% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 18.4 MB, less than 97.92% of C++ online submissions for Validate Binary Search Tree.

// https://leetcode.com/problems/validate-binary-search-tree/discuss/32109/My-simple-Java-solution-in-3-lines

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
    bool isValidBST(TreeNode* root) {
        return recursive(root, LONG_MIN, LONG_MAX);
    }
    
    bool recursive(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) return true;
        if (minVal >= root->val || maxVal <= root->val) return false;
        return recursive(root->left, minVal, root->val) && recursive(root->right, root->val, maxVal);
    }
};
