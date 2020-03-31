// Runtime: 8 ms, faster than 38.82% of C++ online submissions for Subsets.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Subsets.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combination;
        vector<int> emptyList;
        combination.push_back(emptyList);
        
        for (int n: nums) {
            vector<vector<int>> newCombList;
            for (auto oldComb: combination) {
                oldComb.push_back(n);
                newCombList.push_back(oldComb);
            }
            combination.insert(combination.end(), newCombList.begin(), newCombList.end());
        }
        
        return combination;
    }
};
