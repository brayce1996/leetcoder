class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int size = queries.size();
        vector<vector<int>> snapshot;
        vector<bool> answer(size);
        
        vector<int> frist(26, 0);
        frist[s[0] - 'a'] += 1;
        snapshot.push_back(frist);
        
        // prefix sum string s and snapshot them all
        for (int i = 1; i < s.length(); i++) {
            vector<int> charPrefixSum(snapshot[i - 1].begin(), snapshot[i - 1].end());
            charPrefixSum[s[i] - 'a'] += 1;
            snapshot.push_back(charPrefixSum);
        }
        
        for (int i = 0; i < size; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int replaceNum = queries[i][2];
            
            // count odd numbers
            int oddNum = 0;
            if (start == 0) {
                for (int j = 0; j < 26; j++) {
                    oddNum += snapshot[end][j] % 2;
                }
            } else {
                for (int j = 0; j < 26; j++) {
                    oddNum += (snapshot[end][j] - snapshot[start - 1][j]) % 2;
                }
            }
            answer[i] = (replaceNum >= oddNum / 2);
        }
        return answer;
    }
};