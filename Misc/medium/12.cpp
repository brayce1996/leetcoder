class Solution {
public:
    string intToRoman(int num) {
        int digitCount[7] = {0};
        int values[] = {1000, 500, 100, 50, 10, 5, 1};
        int symbols[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        
        for (int i = 0; i < 7; i++) {
            digitCount[i] = num / values[i];
            num %= values[i];
        }
        
        string result = "";
        for (int j = 0; j < digitCount[0]; j++)
            result += symbols[0];
        for (int i = 2; i < 7; i += 2) {
            if (digitCount[i] >= 4) {
                result += symbols[i];
                if (digitCount[i - 1] >= 1) {
                    result += symbols[i - 2];
                } else {
                    result += symbols[i - 1];
                }
            } else {
                if (digitCount[i - 1] >= 1)
                    result += symbols[i - 1];
                
                for (int j = 0; j < digitCount[i]; j++)
                    result += symbols[i];
            }
            
        }
        
        return result;
    }
};