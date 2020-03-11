// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Divide Two Integers.

class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int u_dividend = (dividend == 0x80000000)? 0x80000000 : abs(dividend);
        unsigned int u_divisor = (divisor == 0x80000000)? 0x80000000 : abs(divisor);
        
        unsigned int quo = 0;
        while(u_dividend >= u_divisor && u_dividend <= 0x80000000) {
            int expo2 = 0;
            while(expo2 < 31) {
                int nextExpo2 = expo2 + 1;

                // add unsigned for speed up a little
                if (u_dividend < (u_divisor << (unsigned)nextExpo2))
                    break;
                
                // next expo will overflow, avoid it
                if ((u_divisor << (unsigned)nextExpo2) < (u_divisor << (unsigned)expo2))
                    break;
                expo2++;   
            }
            quo += 1 << expo2;
            u_dividend -= u_divisor << expo2;
            cout << expo2 << endl;
        }
        if (quo == 0x80000000) return ((dividend < 0) == (divisor < 0))? 0x7fffffff : 0x80000000;
        else return ((dividend < 0) == (divisor < 0))? quo : -quo;
    }
};