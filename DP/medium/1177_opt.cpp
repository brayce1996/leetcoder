class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> prefixSum(1);
        int mask = 0;
        for (int i = 0; i < s.length(); i++) {
            mask = mask ^ (1 << (s[i] - 'a'));
            prefixSum.push_back(mask);
        }
        vector<bool> ans;
        for (auto query: queries) {
            unsigned int diff = prefixSum[query[1] + 1] ^ prefixSum[query[0]];
            int oddNum = __builtin_popcount(diff);
            ans.push_back(query[2] >= oddNum / 2);
        }
        return ans;
    }
    
    // O = Odd, Even = E
    // O + O = E
    // E + O = O + E = O
    // E + E = E

    // start diff  end
    //   E    E     E
    //   E    O     O
    //   O    E     O
    //   E    E     E

    // then swap "diff" and "end"

    // start end   diff
    //   E    E     E
    //   E    O     O
    //   O    E     O
    //   E    E     E

    // and let O = 1, E = 0

    // start end   diff
    //   0    0     0
    //   0    1     1
    //   1    0     1
    //   1    1     0

    // it is a XOR operation
};