// Runtime: 4 ms, faster than 98.70% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Longest Palindromic Substring.
// reference: https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) return s;
        int maxLen = 1;
        int maxStart = 0;
        int mid = 0;
        while (mid < len) {
            int start = mid;
            int end = mid;
            
            // skip duplicated
            while (end < len - 1) {
                if (s[end] != s[end + 1])
                    break;
                end++;
            }
            
            mid = end + 1;
            
            while (end < len - 1 && start > 0) {
                if (s[start - 1] == s[end + 1]) {
                    start--;
                    end++;
                } else break;
            }
            
            if (end - start + 1 > maxLen) {
                maxLen = end - start + 1;
                maxStart = start;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
};
