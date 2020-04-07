// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Longest Increasing Subsequence.
// God Like solution: https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size(), 0);
        int currSize = 0;
        for (auto n: nums) {
            int low = 0;
            int high = currSize;
            while (low < high) {
                int mid = (low + high) / 2;
                if (tails[mid] < n) {
                    low = mid + 1;
                } else high = mid;
            }
            tails[low] = n;
            if (low == currSize)
                currSize++;
        }
        return currSize;
    }
};