// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
// Memory Usage: 5.9 MB, less than 100.00% of C++ online submissions for Pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        double currPow = x;
        int lastPow = abs(n);
        for (int i = 1; i <= 32 && lastPow > 0; i++, lastPow = lastPow >> 1) {
            if (lastPow % 2 == 1) {
                result *= currPow;
            }
            currPow  = currPow * currPow;
        }
        
        return (n > 0)? result : 1/result;
    }
};
