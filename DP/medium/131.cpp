// Runtime: 36 ms, faster than 58.39% of C++ online submissions for Palindrome Partitioning.
// Memory Usage: 12.5 MB, less than 100.00% of C++ online submissions for Palindrome Partitioning.

class Solution {
public:
    vector<vector<string>> combinations;
    vector<vector<bool>> memo;
    vector<vector<string>> partition(string s) {
        
        memo = getAllPalindrome(s);
        for (auto row: memo) {
            for (auto col: row) {
                cout << col << " ";   
            }
            cout << endl;
        }
        
        vector<string> curr;
        dfs(s, 0, curr);
        return combinations;
    }
    
    void dfs(string s, int start, vector<string>& curr) {
        if (start == s.length()) {
            combinations.push_back(curr);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (memo[start][end]) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<bool>> getAllPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> memo(len, vector<bool>(len, false));
        int mid = 0;
        
        for (int i = 0; i < len; i++)
            memo[i][i] = true;
        
        while (mid < len) {
            int start = mid;
            int end = mid;
            while (end < len - 1 && s[end] == s[end + 1]) {
                memo[end][end + 1] = true;
                end++;
            }
            mid = end + 1;
            while (end < len && start >= 0 && s[start] == s[end]) {
                memo[start][end] = true;
                start--;
                end++;
            }
        }
        return memo;
    }
};
