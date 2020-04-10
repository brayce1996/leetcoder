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
    unordered_map<int, int> hashMap;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int mode = 0;
        for (auto kv: hashMap) {
            mode = max(mode, kv->second);
        }
        vector<int> ansList;
        for (auto kv: hashMap) {
            if (kv.second == mode) {
                ansList.push_back(kv.first);
            }
        }
        
        return ansList;
    }
    
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        if (hashMap.find(root->val) != hashMap.end()) {
            hashMap[root->val] += 1;
        } else hashMap[root->val] = 1;
        dfs(root->left);
        dfs(root->right);
    }
};
