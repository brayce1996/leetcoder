// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Divide Two Integers.
class Solution {
public:
    int divide(int dividend, int divisor) {
        // overflow case
        if (dividend == 0x80000000 && divisor == -1) {
            return 0x7fffffff;
        } else if (dividend == 0x80000000 && divisor == 1) {
            return 0x80000000;
        }

        bool positive = true;
        if (dividend < 0) {
            positive = !positive;
            dividend = (dividend == 0x80000000)? 0x80000000 : -dividend;
        }
        if (divisor < 0) {
            positive = !positive;
            divisor = (divisor == 0x80000000)? 0x80000000 : -divisor;
        }
        unsigned int u_dividend = dividend;
        unsigned int u_divisor = divisor;

        vector<unsigned int> divisorList = {u_divisor};
        vector<unsigned int> quoList = {1};
        int index = 0;
        unsigned int mulDiv;
        while(true) {
            mulDiv = divisorList[index];
            if (mulDiv == u_dividend) {
                unsigned int lastQuo = quoList[quoList.size() - 1];
                return (positive)? lastQuo : -((signed)lastQuo);
            } else if (mulDiv > u_dividend) break;
            else {
                divisorList.push_back(mulDiv + mulDiv);
                index++;
                unsigned int lastQuo = quoList[quoList.size() - 1];
                quoList.push_back(lastQuo + lastQuo);
            }
        }
        
        cout << mulDiv << " " << divisorList.size() << " " << quoList.size() << endl;

        // divisor > dividend
        if (quoList.size() < 2) {
            return 0;
        }
        
        unsigned int lowVal = divisorList[index - 1];
        unsigned int quo = quoList[index - 1];
        unsigned int highVal = divisorList[index];
        index = index - 2;
        while (index >= 0) {
            unsigned int midVal = lowVal + divisorList[index];
            if (midVal == u_dividend) {
                quo += quoList[index];
                return (positive)? quo : -quo;
            } else if (midVal > u_dividend) {
                highVal = midVal;
            } else {
                lowVal = midVal;
                quo += quoList[index];
            }
            index--;
        }
        return (positive)? quo : -((signed)quo);
    }
};
