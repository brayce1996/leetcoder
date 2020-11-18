class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> charCount;
        vector<string> ans;

        for (char ch: s) {
            charCount[ch]++;
        }

        char oddChar = 0;
        for (auto pair: charCount) {
            if (pair.second % 2) {
                // only one can be odd
                if (oddChar != 0) return ans;
                else {
                    oddChar = pair.first;
                }
            }
        }

        string middle = "";
        if (oddChar != 0) {
            middle.push_back(oddChar);
            charCount[oddChar] -= 1;
        }


        // dfs expanding
        helper(ans, charCount, middle, s.size());
        return ans;
    }

    void helper(vector<string> &ans, unordered_map<char, int>& charCount, string middle, int sLen) {
        if (middle.size() == sLen) {
            ans.push_back(middle);
            return;
        }

        for (auto pair: charCount) {
            if (pair.second > 0) {
                charCount[pair.first] -= 2;
                helper(ans, charCount, pair.first + middle + pair.first, sLen);
                charCount[pair.first] += 2;
            }
        }

    }
};
