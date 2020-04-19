class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, bool> reachable;
        for (auto word: wordList) {
            reachable[word] = true;
        }
        
        queue<string> wordQueue;
        queue<string> nextQueue;
        wordQueue.push(beginWord);
        
        int ladderCount = 1;
        // O(N^2 * Len)
        while (!wordQueue.empty() || !nextQueue.empty()) {
            if (wordQueue.empty()) {
                wordQueue = nextQueue;
                queue<string>().swap(nextQueue); // clear
                ladderCount++;
            }
            string curr = wordQueue.front();
            wordQueue.pop();
            
            for (auto word: wordList) {
                if (reachable[word] && oneLadder(curr, word)) {
                    if (word == endWord) return ladderCount + 1;
                    reachable[word] = false;
                    nextQueue.push(word);
                }
            }
        }
        return 0;
    }
    
    bool oneLadder(string src, string dst) {
        int diffCount = 0;
        for (int i = 0; i < src.size(); i++) {
            if (src[i] != dst[i]) {
                if (diffCount > 0) return false;
                diffCount++;
            }
        }
        return true; // diff <= 1
    }
};
