// Runtime: 24 ms, faster than 89.13% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 16.1 MB, less than 6.06% of C++ online submissions for Product of Array Except Self.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> reversePrefixProduct(size);
        reversePrefixProduct[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            reversePrefixProduct[i] = reversePrefixProduct[i + 1] * nums[i];
        }
        
        int prefixProduct = 1;
        vector<int> result(size);
        for (int i = 0; i < size - 1; i++) {
            result[i] = prefixProduct * reversePrefixProduct[i + 1];
            prefixProduct *= nums[i];
        }
        result[size - 1] = prefixProduct;
        
        return result;
    }
};
