// Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for House Robber.

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < 3; i++) nums.push_back(0);
        for (int i = size - 1; i >= 0; i--) {
            nums[i] = max(nums[i + 2] + nums[i], nums[i + 3] + nums[i]);
        }
        return max(nums[0], nums[1]);
    }
};
