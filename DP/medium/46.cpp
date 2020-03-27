// Runtime: 12 ms, faster than 56.43% of C++ online submissions for Permutations.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> combinations;

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() > 0) {
            vector<int> currPerm;
            vector<bool> numsSelTable(nums.size(), true);
            dfs(nums, currPerm, numsSelTable, nums.size());
        }
        return combinations;
    }
    
    void dfs(vector<int>& nums, vector<int>& currPerm, vector<bool>& numsSelTable, int restCount) {
        if (restCount == 0) {
            combinations.push_back(currPerm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (numsSelTable[i]) {
                numsSelTable[i] = false;
                currPerm.push_back(nums[i]);
                dfs(nums, currPerm, numsSelTable, restCount - 1);
                currPerm.pop_back();
                numsSelTable[i] = true;
            }

        }
    }
};
