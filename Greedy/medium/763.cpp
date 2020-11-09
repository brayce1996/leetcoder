class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> part;

        // index right bound
        unordered_map<char, int> rightBound;
        for (int i = 0; i < S.size(); ++i) {
            rightBound[S[i]] = i;
        }

        // partitioning
        int lastPartStart = 0;
        int lastPartEnd = 0;
        while (lastPartEnd < S.size()) {
            // expand a partition
            for (int i = lastPartStart; i <= lastPartEnd; ++i) {
                lastPartEnd = max(lastPartEnd, rightBound[S[i]]);
            }

            part.push_back(lastPartEnd - lastPartStart + 1);

            lastPartEnd += 1;
            lastPartStart = lastPartEnd;
        }

        return part;
    }
};
