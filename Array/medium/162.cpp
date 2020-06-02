class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            long left = LONG_MIN;
            long right = LONG_MIN;
            
            if (mid > 0) left = nums[mid - 1];
            if (mid < nums.size() - 1) right = nums[mid + 1];
            
            if (left < nums[mid] && nums[mid] > right)
                return mid;
            else if (left < nums[mid] && nums[mid] < right)
                low = mid + 1;
            else high = mid - 1;
        }
        return 0;
    }
};
