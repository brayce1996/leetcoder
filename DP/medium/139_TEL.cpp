class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<vector<bool>> memo(len, vector<bool>(len, false));
        
        for (string word: wordDict) {
            for (int start = 0; start < len; start++) {
                int foundIdx = s.find(word, start);
                if (foundIdx == std::string::npos) break;
                else {
                    memo[foundIdx][foundIdx + word.length() - 1] = true;
                }
            }
        }
        
        for (auto row: memo) {
            for (auto col: row) cout << col << " ";
            cout << endl;
        }
        
        return dfs(memo, 0);
    }
    
    bool dfs(vector<vector<bool>>& memo, int start) {
        if (start >= memo.size()) return true;
        
        bool result = false;
        for (int end = start; end < memo.size(); end++) {
            if (result) break;
            else if (memo[start][end]) {
                result |= dfs(memo, end + 1);
            }
        }
        return result;
    }
};
