class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size();
        while (true) {
            int pivot = start;
            int low = start + 1;
            int high = end - 1;
            while (low < high) {
                if (nums[low] < nums[pivot]) low++;
                else if (nums[high] > nums[pivot]) high--;
                else swap(nums[low++], nums[high--]);
            }
            swap(nums[pivot], nums[high]);

            if (high + 1 == k) return nums[high];
            else if (high + 1 < k) start = high + 1;
            else end = high;
        }
    }
};
