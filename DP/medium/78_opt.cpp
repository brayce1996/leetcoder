// Runtime: 4 ms, faster than 97.23% of C++ online submissions for Subsets.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Subsets.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> combination;
        vector<int> emptyList;
        combination.push_back(emptyList);
        
        for (int n: nums) {
            int len = combination.size();
            for (int i = 0; i < len; i++) {
                vector<int> tmpComb = combination[i];
                tmpComb.push_back(n);
                combination.push_back(tmpComb);
            }
        }
        
        return combination;
    }
};
