// Runtime: 72 ms, faster than 20.00% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastPos;
        
        int longest = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (lastPos.find(s[i]) != lastPos.end() && lastPos[s[i]] >= start) {
                start = lastPos[s[i]] + 1;
            }
            
            lastPos[s[i]] = i;
            longest = max(longest, i - start + 1);
        }
        
        return longest;
    }
};
