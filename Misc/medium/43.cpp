class Solution {
public:
    string multiply(string num1, string num2) {
        
        // reverse so the numbers are Most Significant Endian
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // init result
        vector<int> result(num1.size() * num2.size() + 1, 0);
        
        // start multiply
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                // do multiply, and ignore carry at this time
                result[j + i] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        // carry at once
        int carry = 0;
        for (int i = 0; i < result.size() - 1; i++) {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        
        // convert result back to string
        return toString(result);
    }
    
    string toString(vector<int> &big) {
        string res = "";
        
        bool firstNoneZero = false;
        for (int i = big.size() - 1; i >= 0; i--) {
            if (firstNoneZero || big[i] != 0) {
                firstNoneZero = true;
                res += to_string(big[i]);
            }
        }
        
        return (res == "") ? "0" : res;
    }
};
