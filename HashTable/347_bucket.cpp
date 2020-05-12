// Runtime: 40 ms, faster than 21.31% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 15.7 MB, less than 6.45% of C++ online submissions for Top K Frequent Elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        vector<vector<int>> bucket(nums.size() + 1, vector<int>());
        
        for (int n: nums) {
            numCount[n] += 1;
        }
        
        for (auto it: numCount) {
            bucket[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for (int i = bucket.size() - 1; i > 0 && ans.size() < k; i -= 1) {
            if (!bucket[i].empty()) {
                for (int n: bucket[i]) {
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
};
