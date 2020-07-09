class Solution {
public:
    int longestSubstring(string s, int k) {
        int result = 0;
        for (int uniqueLimit = 1; uniqueLimit <= 26; uniqueLimit++) {
            result = max(result, slidingWindow(s, k, uniqueLimit));
        }
        return result;
    }
    
    int slidingWindow(string s, int k, int uniqueLimit) {
        vector<int> occurence(128, 0);
        int begin = 0;
        int end = 0;
        int maxLen = 0;
        int uniqueCount = 0;
        int atLeastKCount = 0;
        while (begin <= end) {
            if (end < s.length() && uniqueCount <= uniqueLimit) {
                // can expand substr at end
                if (occurence[s[end]] == 0)
                    uniqueCount += 1;
                
                occurence[s[end]] += 1;
                
                if (occurence[s[end]] == k)
                    atLeastKCount += 1;
                
                end += 1;
            } else {
                // should shrink substr from begin
                if (occurence[s[begin]] == k)
                    atLeastKCount -= 1;
                
                occurence[s[begin]] -= 1;
                
                if (occurence[s[begin]] == 0)
                    uniqueCount -= 1;
                
                begin += 1;
            }
            
            if (uniqueCount == atLeastKCount) {
                maxLen = max(maxLen, end - begin);
            }
        }
        
        return maxLen;
    }
};