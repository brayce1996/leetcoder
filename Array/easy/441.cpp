// Runtime: 4 ms, faster than 85.28% of C++ online submissions for Arranging Coins.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Arranging Coins.

class Solution {
public:
    int arrangeCoins(int n) {
        long high = 0x7fffffff;
        long low = 0;
        while(low < high) {
            long mid = (low + high) / 2;
            if (mid * (mid+1) / 2 > n) high = mid;
            else low = mid + 1;
        }
        return low - 1;
    }
};
