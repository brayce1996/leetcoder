// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wiggle Subsequence.
// Memory Usage: 7.1 MB, less than 92.86% of C++ online submissions for Wiggle Subsequence.

#define EQUAL       0
#define POSITIVE    1
#define NEGATIVE    2

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        
        int wiggleCounter = 0;
        int lastDelta = EQUAL; // init as EQUAL, so next pos/neg delta can be count as a wiggle
        for (int i = 0; i < nums.size() - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            int currDelta;
            
            if (diff > 0) currDelta = POSITIVE;
            else if (diff < 0) currDelta = NEGATIVE;
            else currDelta = EQUAL;
            
            if (currDelta != EQUAL && lastDelta != currDelta) {
                wiggleCounter += 1;
                lastDelta = currDelta; // don't pass EQUAL, remain last pos/neg delta
            }
            
        }
        
        return wiggleCounter + 1; // +1 for tarsferring interval count to node count
    }
};