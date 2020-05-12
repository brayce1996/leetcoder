// Runtime: 68 ms, faster than 5.28% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 17.2 MB, less than 6.45% of C++ online submissions for Top K Frequent Elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<unordered_set<int>> numCount(2, unordered_set<int>());
        unordered_map<int, int> numToCurrCount;
        
        for (int n: nums) {
            if (numToCurrCount.find(n) != numToCurrCount.end()) {
                numCount[numToCurrCount[n]].erase(n);
                numToCurrCount[n] += 1;
                if (numCount.size() <= numToCurrCount[n]) {
                    unordered_set<int> newLevel;
                    newLevel.insert(n);
                    numCount.push_back(newLevel);
                } else {
                    numCount[numToCurrCount[n]].insert(n);
                }
            } else {
                numToCurrCount[n] = 1;
                numCount[1].insert(n);
            }
        }
        
        vector<int> ans;
        for (int level = numCount.size() - 1; level > 0 && ans.size() < k; level -= 1) {
            for (auto n: numCount[level]) {
                ans.push_back(n);
            }
        }
        return ans;
    }
};
