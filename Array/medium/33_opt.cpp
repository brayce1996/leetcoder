class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int leftBound = 0, rightBound = size - 1;
        int mid = 0;
        // find min position
        while (leftBound < rightBound) {
            mid = (leftBound + rightBound) / 2;
            if (nums[mid] > nums[rightBound]) leftBound = mid + 1;
            else rightBound = mid;
        }
        
        int shift = leftBound; // leftBound == rightBound
        
        int realMid;
        leftBound = 0;
        rightBound = size - 1;
        while (leftBound <= rightBound) {
            mid = (leftBound + rightBound) / 2;
            realMid = (mid + shift) % size;
            if (nums[realMid] == target) return realMid;
            else if (nums[realMid] > target) rightBound = mid - 1;
            else leftBound = mid + 1;
        }
        return -1; // not found
    }
};
