class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int currMinStep = 1;
        
        for (int i = nums.size() - 2; i > 0; i--) {
            if (currMinStep <= nums[i]) currMinStep = 1;
            else currMinStep++;
        }
        
        if (nums[0] >= currMinStep) return true;
        else return false;
    }
};
