class Ladder {
public:
    string word;
    bool canReach; // back tracking
    
    Ladder(string word) {
        this->word = word;
        this->canReach = true;
    }
};

class Solution {
public:
    int minLadder = INT_MAX;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<Ladder*>> ladderTable(wordList.size() + 1, vector<Ladder*>(0));
        // O(N * Len)
        buildLadderTable(beginWord, wordList, ladderTable);
        printLadderTable(ladderTable);
        
        // O(N * Len)
        dfs(beginWord, endWord, ladderTable, 1);
        return (minLadder < INT_MAX)? minLadder : 0;
    }
    
    void dfs(string src, string dst, vector<vector<Ladder*>>& ladderTable, int ladderCount) {
        // cout << ladderCount << " " << src << endl;
        if (ladderCount >= minLadder) return;
        if (src == dst) {
            minLadder = min(ladderCount, minLadder);
            return;
        }
        int diffCount = (ladderCount > src.size()) ? src.size() : ladderCount;
        for (auto ladder: ladderTable[diffCount]) {
            if (ladder->canReach && isOneLadder(src, ladder->word)) {
                ladder->canReach = false;
                dfs(ladder->word, dst, ladderTable, ladderCount + 1);
                ladder->canReach = true;
            }
        }
    }
    
    // O(Len)
    bool isOneLadder(string src, string dst) {
        int diffCount = 0;
        for (int i = 0; i < src.length(); i++) {
            if (src[i] != dst[i]) {
                diffCount++;
                if (diffCount > 1) return false;
            }
        }
        return true; // diffCount <= 1
    }
    
    void buildLadderTable(
        string beginWord, 
        vector<string>& wordList, 
        vector<vector<Ladder*>>& ladderTable) {
        
        for (string word: wordList) {
            int diff = countDiff(beginWord, word);
            Ladder* newLadder = new Ladder(word);
            ladderTable[diff].push_back(newLadder);
        }
    }
    
    int countDiff(string a, string b) {
        int diffCount = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                diffCount++;
            }
        }
        return diffCount;
    }
    
    void printLadderTable(vector<vector<Ladder*>>& ladderTable) {
        for (auto ladderLevel: ladderTable) {
            for (auto ladder: ladderLevel) {
                cout << ladder-> word << " ";
            }
            cout << endl;
        }
    }
};
