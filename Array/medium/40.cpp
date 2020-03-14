// Runtime: 8 ms, faster than 82.61% of C++ online submissions for Combination Sum II.
// Memory Usage: 9 MB, less than 94.74% of C++ online submissions for Combination Sum II.

class Solution {
public:
    vector<vector<int>> combiList;
    unordered_map<int, int> canTable;
    vector<int> uniqueCanList;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (!candidates.empty()) {
            sort(candidates.begin(), candidates.end());
            int lastCan = -1;
            for (int can: candidates) {
                if (lastCan != can) { // first meet this number
                    canTable[can] = 1;
                    uniqueCanList.push_back(can);
                } else canTable[can] = canTable[can] + 1;
                lastCan = can;
            }
            vector<int> currCombi;
            combi(target, currCombi, 0);
        }
        return combiList;
    }
    
    void combi(int target, vector<int>& currCombi, int uniqueCanIndex) {
        if (uniqueCanIndex >= uniqueCanList.size())
            return;
        
        for (int i = uniqueCanIndex; i < uniqueCanList.size(); i++) {
            if (canTable[uniqueCanList[i]] < 1) 
                continue;
            
            int nextTarget = target - uniqueCanList[i];
            if (nextTarget == 0) {
                currCombi.push_back(uniqueCanList[i]);
                combiList.push_back(currCombi);
                currCombi.pop_back();
                return;
            } else if (nextTarget > 0) {
                currCombi.push_back(uniqueCanList[i]);
                canTable[uniqueCanList[i]] -= 1;
                //print(currCombi);
                combi(nextTarget, currCombi, i);
                currCombi.pop_back();
                canTable[uniqueCanList[i]] += 1;
            }
        }
    }
    
    void print(vector<int>& currCombi) {
        for (auto can: currCombi) {
            cout << can;
        }
        cout << endl;
    }
};
