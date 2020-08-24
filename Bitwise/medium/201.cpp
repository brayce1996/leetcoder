class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // collect zeros = find num between n~m that num % 2^k == 0 where k is 1 to 31
        unsigned int result = m & n;
        unsigned int diff = n - m;
        for (unsigned int mask = 1; mask <= diff; mask <<= 1) {
            result &= ~mask;
        }
        return result;
    }
};
