class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // from right to left, find the first nums[i-1] < nums[i], name nums[i-1] A
        int currentHeadIndex = -1;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i-1] < nums[i]) {
                currentHeadIndex = i-1;
                break;
            }
        }

        // not found possible next permu., sort it in ascending order
        if (currentHeadIndex == -1) {
            sort(nums.begin(), nums.end());
            return;
        }

        // from i to nums.size()-1, find the minimum number larger than A, name it B
        int nextHeadIndex = nums.size() - 1;
        for (int i = currentHeadIndex + 1; i < nums.size(); ++i) {
            if (nums[currentHeadIndex] >= nums[i]) {
                nextHeadIndex = i - 1;
                break;
            }
        }

        // swap A and B position
        swap(nums[currentHeadIndex], nums[nextHeadIndex]);

        // sort from i to nums.size()-1
        sort(nums.begin()+currentHeadIndex+1, nums.end());
    }
};
