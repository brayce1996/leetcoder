/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        int levelCount = 0;
        while (true) {
            levelCount++;
            queue<TreeNode*> nextQueue;
            while (!bfsQueue.empty()) {
                TreeNode *curr = bfsQueue.front();
                bfsQueue.pop();
                if (curr->left == NULL && curr->right == NULL) {
                    return levelCount;
                }

                if (curr->left) nextQueue.push(curr->left);
                if (curr->right) nextQueue.push(curr->right);
            }

            bfsQueue = nextQueue;
        }
        return -1;
    }
};
