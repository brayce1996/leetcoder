// Runtime: 12 ms, faster than 99.95% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 15.6 MB, less than 6.06% of C++ online submissions for Product of Array Except Self.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size);
        
        // reversed prefix product
        ans[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i];
        }
        
        // prefix product * reversed prefix product
        int prefixProduct = 1;
        for (int i = 0; i < size - 1; i++) {
            ans[i] = prefixProduct * ans[i + 1];
            prefixProduct *= nums[i];
        }
        ans[size - 1] = prefixProduct;
        
        return ans;
    }
};
