// Runtime: 4 ms, faster than 34.56% of C++ online submissions for Fraction to Recurring Decimal.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Fraction to Recurring Decimal.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long, int> occurPos; // repeat number : dividing iteration
        long den = abs(denominator);
        long num = abs(numerator);
        string result = to_string(num / den);
        long nextNum = (num % den) * 10;
        if (nextNum != 0) result +=  ".";
        
        int index = result.length();
        
        while (nextNum != 0 && occurPos.find(nextNum) == occurPos.end()) {
            occurPos[nextNum] = index;
            result += to_string(nextNum / den);
            nextNum = (nextNum % den) * 10;
            index++;
        }
        
        if (nextNum != 0) {
            result.insert(occurPos[nextNum], 1, '(');
            result += ')';
        }
        
        return ((long)numerator * (long)denominator < 0) ? "-" + result : result;
    }
};
