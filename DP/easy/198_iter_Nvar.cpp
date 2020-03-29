// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for House Robber.
// Reference: https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};
