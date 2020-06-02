class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        
        // find the index where is the starting point needed to be reordering
        int reorderStart = 0;
        for (int i = size - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                reorderStart = i;
                break;
            }
        }
        
        // reordering step 1
        // since the numbers start from reorderStart are descending
        // reversing them will "sort" them in ascending way
        reverse(nums, reorderStart, size - 1);
        
        
        if (reorderStart > 0) {
            // reordering step 2: 
            // binary searching the index of min value larger than heading number
            int swapTarget = nums[reorderStart - 1];
            int low = reorderStart;
            int high = size - 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (nums[mid] <= swapTarget) {
                    low = mid + 1;
                } else high = mid;
            }
            nums[reorderStart - 1] = nums[low];
            nums[low] = swapTarget;
            
        }
    }
    
private:
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
};
