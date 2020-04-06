// Runtime: 132 ms, faster than 5.04% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Longest Increasing Subsequence.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int size = nums.size();
        vector<int> memo(size, 1);
        int ans = 0;
        for (int i = 0; i < size; i++) {
            int preMax = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j] && memo[j] > preMax) {
                    preMax = memo[j];
                }
            }
            memo[i] += preMax;
            ans = max(memo[i], ans);
        }
        
        return ans;
    }
};