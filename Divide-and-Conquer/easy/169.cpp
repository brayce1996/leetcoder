class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 0;
        int currNum = nums[0];
        for (int n: nums) {
            if (currNum == n) {
                count++;
            } else if (count < 2) {
                count = 1;
                currNum = n;
            } else count--;
        }
        
        return currNum;
    }
};
