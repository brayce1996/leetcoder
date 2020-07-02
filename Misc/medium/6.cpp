// Runtime: 16 ms, faster than 96.77% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 7.8 MB, less than 92.67% of C++ online submissions for ZigZag Conversion.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.length() || numRows < 2) return s;
        
        string result = "";
        for (int row = numRows; row > 0; row--) {
            int index = numRows - row;
            for (int col = 0; index < s.length(); col++) {
                result += s[index];
                int step = (col % 2) ? (numRows - row) * 2 : (row - 1) * 2;
                
                // special cases for top and bottom rows
                if (step == 0)
                    step = (row - 1 == 0) ? (numRows - row) * 2 : (row - 1) * 2;
                
                index += step;
            }
        }
        return result;
    }
};