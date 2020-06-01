class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int sortStartIndex = 0;
        for (int i = size - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                sortStartIndex = i;
                break;
            }
        }
        sort(nums.begin() + sortStartIndex, nums.end());
        if (sortStartIndex == 0) {
            return;
        }
        
        int swapTarget = nums[sortStartIndex - 1];
        
        int low = sortStartIndex;
        int high = size - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= swapTarget) {
                low = mid + 1;
            } else high = mid;
        }
        nums[sortStartIndex - 1] = nums[low];
        nums[low] = swapTarget;
    }
};
