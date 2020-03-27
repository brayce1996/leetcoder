// Runtime: 4 ms, faster than 87.00% of C++ online submissions for Generate Parentheses.
// Memory Usage: 15.3 MB, less than 79.34% of C++ online submissions for Generate Parentheses.

class Solution {
public:
    vector<string> combination;
    
    vector<string> generateParenthesis(int n) {
        dfs("", n, n, 0);
        return combination;
    }
    
    void dfs(string currPars, int leftParCount, int rightParCount, int leftRightDiff) {
        if (rightParCount == 0) { // reach the end
            combination.push_back(currPars);
            return;
        }
        
        if (leftParCount > 0)
            dfs(currPars + '(', leftParCount - 1, rightParCount, leftRightDiff + 1);
        
        if (leftRightDiff > 0)
            dfs(currPars + ')', leftParCount, rightParCount - 1, leftRightDiff - 1);
    }
};
