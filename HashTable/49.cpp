// Runtime: 112 ms, faster than 42.90% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.3 MB, less than 68.66% of C++ online submissions for Group Anagrams.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> anaMapIndex;
        vector<vector<string>> ans;
        
        for (string s: strs) {
            string sKey = s;
            sort(sKey.begin(), sKey.end());
            
            if (anaMapIndex.find(sKey) != anaMapIndex.end()) {
                ans[anaMapIndex[sKey]].push_back(s);
            } else {
                vector<string> newGroup(1, s);
                ans.push_back(newGroup);
                anaMapIndex[sKey] = ans.size() - 1;
            }
        }
        return ans;
    }
};