// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.3 MB, less than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
    vector<string> combinations;
    vector<string> letterTable = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() > 0) {
            string currLetters = "";
            dfs(digits, 0, currLetters);   
        }
        return combinations;
    }
    
    void dfs(string digits, int index, string currLetters) {
        if (digits.length() == index) { // reach the end
            combinations.push_back(currLetters);
            return;
        }
        
        for (char c: letterTable[digits[index] - '1']) {
            dfs(digits, index + 1, currLetters + c);
        }
    }
    
};
