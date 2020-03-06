// Runtime: 12 ms, faster than 79.38% of C++ online submissions for The K Weakest Rows in a Matrix.
// Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for The K Weakest Rows in a Matrix.

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        vector<pair<int, int>> soldierCount(rowSize, pair<int, int>(-1, -1));
        for (int row = 0; row < rowSize; row++) {
            soldierCount[row].first = row; // index
            for (int col = 0; col < colSize; col++) {
                if (mat[row][col] == 0) {
                    soldierCount[row].second = col; // soldier count
                    break;
                }
            }
            if (soldierCount[row].second == -1)
                soldierCount[row].second = colSize;
        }
        
        sort(soldierCount.begin(), soldierCount.end(), sortPair);
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(soldierCount[i].first);
            cout << soldierCount[i].second << endl;
        }
        return ans;
    }
    
private:
    static bool sortPair(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else return a.second < b.second;
    }
};
