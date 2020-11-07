class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty())
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> src(nums.size(), -1);

        int maxSet = 0;

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    src[i] = j;
                }
            }
            if (dp[i] > dp[maxSet]) {
                maxSet = i;
            }
        }

        int next = maxSet;
        vector<int> ans;
        while (next >= 0) {
            ans.push_back(nums[next]);
            next = src[next];
        }

        return ans;
    }
};
