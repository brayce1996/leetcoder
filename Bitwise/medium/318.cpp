class Solution {
public:
    int maxProduct(vector<string>& words) {
        // use a int to store whether a word contains a-z
        vector<int> hash(words.size(), 0);
        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                hash[i] |= 1 << (words[i][j] - 'a');
            }
        }
        
        int maxProd = 0;
        for (int i = 0; i < hash.size(); i++) {
            for (int j = i + 1; j < hash.size(); j++) {
                if ((hash[i] & hash[j]) == 0) {
                    maxProd = max(maxProd, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};
