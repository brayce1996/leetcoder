// Runtime: 16 ms, faster than 96.77% of C++ online submissions for ZigZag Conversion.
// Memory Usage: 7.8 MB, less than 92.67% of C++ online submissions for ZigZag Conversion.

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.length() || numRows < 2) return s;
        
        string result = "";
        for (int row = 0; row < numRows; row++) {
            int index = row;
            for (int col = 0; index < s.length(); col++) {
                result += s[index];
                
                int step;
                if (row == 0) {
                    step = (numRows - row - 1) * 2;
                } else if (row == numRows - 1) {
                    step = row * 2;
                } else {
                    step = (col % 2) ? row * 2 : (numRows - row - 1) * 2;
                }
                
                index += step;
            }
        }
        return result;
    }
};