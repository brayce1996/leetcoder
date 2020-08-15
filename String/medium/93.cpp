class Solution {
public:
    // leading 1, 2 can have 3,2,1 digits
    // leading 3~9 can only have 2, 1 digits
    // leading 0 can only have 1 digits
    int leadNumMaxDigit[10] = {1, 3, 3, 2, 2, 2, 2, 2, 2, 2};
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(ans, s, 0, 3);
        return ans;
    }
    
    bool helper(vector<string>& ans, string s, int startIdx, int remainDot) {
        if (startIdx >= s.size()) return false;
        
        int maxDigit = leadNumMaxDigit[s[startIdx] - '0'];
        int unprocessLen = s.size() - startIdx;
        
        if (remainDot == 0) {
            if (maxDigit >= unprocessLen) {
                int nextNum = stoi(s.substr(startIdx));
                if (nextNum < 256) {
                    ans.push_back(s);
                    return true;
                }
            }
            return false;
        }
        
        bool hasValidAns = false;
        for (int d = min(maxDigit, unprocessLen - 1); d > 0; d -= 1) {
            int nextNum = stoi(s.substr(startIdx, d));
            if (nextNum > 255) continue;
            
            bool isValid = helper(
                ans,
                s.substr(0, startIdx + d) + "." + s.substr(startIdx + d),
                startIdx + d + 1,
                remainDot - 1);
            hasValidAns |= isValid;
        }
        return hasValidAns;
    }
};
