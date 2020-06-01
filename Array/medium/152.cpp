class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = nums[0];
        
        int minProd = 1;
        int maxProd = 1;
        
        for (int n: nums) {
            minProd *= n;
            maxProd *= n;
            int nextMinProd = min(min(minProd, maxProd), n);
            int nextMaxProd = max(max(minProd, maxProd), n);

            minProd = nextMinProd;
            maxProd = nextMaxProd;
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
