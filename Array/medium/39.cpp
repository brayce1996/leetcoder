// Runtime: 8 ms, faster than 97.62% of C++ online submissions for Combination Sum.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Combination Sum.

class Solution {
public:
    vector<vector<int>> combinations;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (!candidates.empty()) {
            sort(candidates.begin(), candidates.end());
            vector<int> currList;
            dfs(candidates, target, currList, 0);   
        }
        return combinations;
    }

    void dfs(vector<int>& can, int target, vector<int>& currList, int canStart) {
        for (int canIndex = canStart; canIndex < can.size(); canIndex++) {

            int nextTarget = target - can[canIndex];
            if (nextTarget == 0) {
                currList.push_back(can[canIndex]);
                combinations.push_back(currList);
                //print(currList);
                currList.pop_back();
                return;
            } else if (nextTarget > 0 && can[canIndex] <= target / 2) {
                currList.push_back(can[canIndex]);
                dfs(can, nextTarget, currList, canIndex);
                currList.pop_back();
            }
        }
    }

    void print(vector<int>& currList) {
        for (auto num: currList) {
            cout << num << " ";
        }
        cout << endl;
    }
};
