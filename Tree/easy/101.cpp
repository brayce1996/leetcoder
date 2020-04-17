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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        int levelLimit = 1;
        int levelCount = 0;
        int nullCount = 0;
        vector<long> levelVec;
        while(!bfsq.empty()) {
            if (levelCount == levelLimit) {
                levelLimit = (levelLimit - nullCount) * 2;
                levelCount = 0;
                nullCount = 0;
                int size = levelVec.size() / 2;
                for (int i = 0; i < size; i++) {
                    if (levelVec[i] != levelVec[levelVec.size() - i - 1])
                        return false;
                }
                levelVec.clear();
            }
            TreeNode* curr = bfsq.front();
            bfsq.pop();
            if (curr) {
                levelVec.push_back(curr->val);
                bfsq.push(curr->left);
                bfsq.push(curr->right);
            } else { 
                nullCount++;
                levelVec.push_back(LONG_MIN);
            }
            levelCount++;
        }
        return true;
    }
};
