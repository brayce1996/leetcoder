// Runtime: 8 ms, faster than 85.56% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty())
            return ans;
        
        // find left
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            
            if (nums[mid] >= target) high = mid;
            else low = mid + 1;
        }
        ans[0] = low;
        cout << low << endl;
        
        // find right
        low = 0;
        high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2 + (low + high) % 2; // ceiling
            
            if (nums[mid] <= target) low = mid;
            else high = mid - 1;
        }
        ans[1] = high;
        
        cout << high << endl;
        
        if (nums[ans[0]] != target) {
            ans[0] = -1;
            ans[1] = -1;
        }
        
        return ans;
    }
};
