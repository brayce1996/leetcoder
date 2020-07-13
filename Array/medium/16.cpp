class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestDiff = INT_MAX;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end) {
                // count diff
                int currDiff = nums[i] + nums[begin] + nums[end] - target;
                
                // record closest diff
                if (abs(closestDiff) > abs(currDiff))
                    closestDiff = currDiff;
                
                // move end or start to get close to target
                if (currDiff > 0) end -= 1;
                else begin += 1;
            }
        }
        return closestDiff + target;
    }
};
