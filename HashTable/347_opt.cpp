// Runtime: 24 ms, faster than 76.94% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 14.2 MB, less than 6.45% of C++ online submissions for Top K Frequent Elements.Elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        priority_queue<pair<int, int>> pq;
        
        for (int n: nums) {
            numCount[n] += 1;
        }
        
        for (auto it: numCount) {
            pq.push(make_pair(it.second, it.first));
        }
        
        vector<int> ans;
        while(ans.size() < k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
