// Runtime: 8 ms, faster than 85.56% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
            return vector<int>({-1, -1});
        
        // find one of it by standard binary search
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) break;
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        int targetSpot = mid;
        
        cout << mid << endl;
        
        // not found
        if (nums[targetSpot] != target)
            return vector<int>({-1, -1});
        
        // find left
        low = 0;
        while (low < mid) {
            int leftMid = (low + mid) / 2;
            
            if (nums[leftMid] == target) mid = leftMid;
            else low = leftMid + 1;
        }
        
        cout << low << endl;
        
        // find right
        mid = targetSpot; // reset
        high = nums.size() - 1;
        while (mid < high) {
            int rightMid = (mid + high) / 2 + (mid + high) % 2; // flooring
            
            if (nums[rightMid] == target) mid = rightMid;
            else high = rightMid - 1;
        }
        cout << high << endl;
        
        return vector<int>({low, high});
    }
};
