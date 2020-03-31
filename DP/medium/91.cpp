// Runtime: 4 ms, faster than 59.13% of C++ online submissions for Decode Ways.
// Memory Usage: 20.1 MB, less than 11.76% of C++ online submissions for Decode Ways.

class Solution {
public:
    bool isInvalid = false;
    int numDecodings(string s) {
        vector<int> memo(s.length() + 2, -1);
        memo[s.length()] = 1;
        memo[s.length() + 1] = 0;
        int res = recursion(s, 0, memo);
        return (isInvalid) ? 0 : res;
    }
    
    int recursion(string s, int index, vector<int>& memo) {
        if (isInvalid) return 0;
        if (memo[index] >= 0) return memo[index];
        
        if (s[index] == '1') {
            if (index + 1 < s.length() && s[index + 1] == '0') {
                memo[index] = recursion(s, index + 2, memo);
            } else if (index + 2 < s.length() && s[index + 2] == '0') {
                memo[index] = recursion(s, index + 1, memo);
            } else memo[index] = recursion(s, index + 1, memo) + recursion(s, index + 2, memo);
            
        } else if (s[index] == '2') {
            if (index + 1 < s.length() && s[index + 1] == '0') {
                memo[index] = recursion(s, index + 2, memo);
            } else if (index + 1 < s.length() && s[index + 1] > '6') {
                memo[index] = recursion(s, index + 1, memo);
            } else if (index + 2 < s.length() && s[index + 2] == '0') {
                memo[index] = recursion(s, index + 1, memo);
            } else memo[index] = recursion(s, index + 1, memo) + recursion(s, index + 2, memo);
            
        } else if (s[index] == '0') {
            isInvalid = true;
            return 0;
        } else memo[index] = recursion(s, index + 1, memo);
        return memo[index];
    }
};
