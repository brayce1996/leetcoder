// Runtime: 516 ms, faster than 5.93% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 16.8 MB, less than 31.72% of C++ online submissions for Longest Palindromic Substring.

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) return s;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        
        // init
        for (int i = 0; i < len; i++)
            dp[i][i] = true;
        
        int maxLen = 1;
        int maxStart = 0;
        for (int end = 0; end < len; end++) {
            for (int start = end - 1; start >= 0; start--) {
                if ((dp[start + 1][end - 1] || start + 1 == end) && s[end] == s[start]) {
                    dp[start][end] = true;
                    if (end - start + 1 > maxLen) {
                        maxStart = start;
                        maxLen = end - start + 1;
                    }
                }
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
};
