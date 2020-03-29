// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return max(topDownDP(nums, 0, dp), topDownDP(nums, 1, dp));
    }
    
    int topDownDP(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size())
            return 0;
        int jump2Max, jump3Max;
        
        if (index + 2 < nums.size() && dp[index + 2] != -1) {
            jump2Max = dp[index + 2];
        } else jump2Max = topDownDP(nums, index + 2, dp); // jump 2
        
        if (index + 3 < nums.size() && dp[index + 3] != -1) {
            jump3Max = dp[index + 3];
        } else jump3Max = topDownDP(nums, index + 3, dp); // jump 3
        
        dp[index] = max(nums[index] + jump2Max, nums[index] + jump3Max);
        return dp[index];
    }
};
