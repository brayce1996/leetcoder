class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int num: nums) {
            diff ^= num;
        }
        
        diff &= -diff; // remain last bit that a and b are different
        
        vector<int> ans = {0, 0};
        
        // split numbers in two group
        for (int num: nums) {
            if (num & diff) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
};
