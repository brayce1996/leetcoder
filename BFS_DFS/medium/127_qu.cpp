class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> reachable(wordList.begin(), wordList.end());
        
        queue<string> wordQueue;
        wordQueue.push(beginWord);
        
        int ladderLevel = 1;
        while (!wordQueue.empty()) {
            int size = wordQueue.size();
            for (int i = 0; i < size; i++) {
                string curr = wordQueue.front();
                wordQueue.pop();
                for (int charIndex = 0; charIndex < curr.size(); charIndex++) {
                    char tmpChar = curr[charIndex];
                    for (char swapChar = 'a'; swapChar <= 'z'; swapChar++) {
                        curr[charIndex] = swapChar;
                        if (reachable.find(curr) != reachable.end()) {
                            if (curr == endWord) return ladderLevel + 1;
                            reachable.erase(curr);
                            wordQueue.push(curr);
                        }
                    }
                    
                    // restore
                    curr[charIndex] = tmpChar;
                }
            }
            ladderLevel++;
        }
        return 0;
    }
};
