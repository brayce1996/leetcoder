// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Decode Ways.

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        else if (s.length() == 1) return 1;
        int curr = 0;
        int next1 = 1;
        int next2 = 1;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] == '1') {
                if (s[i + 1] == '0') curr = next2;
                else if (s[i + 2] == '0') curr = next1;
                else curr = next1 + next2;
                
            } else if (s[i] == '2') {
                if (s[i + 1] == '0') curr = next2;
                else if (s[i + 1] > '6' || s[i + 2] == '0') curr = next1;
                else curr = next1 + next2;
            } else {
                if (s[i + 1] == '0') return 0;
                curr = next1;
            }
            
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }
};
