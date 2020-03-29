// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size + 3, 0);
        for (int i = size - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 2] + nums[i], dp[i + 3] + nums[i]);
        }
        return max(dp[0], dp[1]);
    }
};
