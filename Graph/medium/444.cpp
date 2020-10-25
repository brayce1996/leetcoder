class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int n = org.size() + 1;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);

        for (auto seq: seqs) {
            // validate all seq elements (seq range in int32)
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] >= n || seq[i] < 1)
                    return false;
            }

            for (int i = 0; i < seq.size() - 1; i++) {
                int node = seq[i];
                int nextNode = seq[i+1];

                adj[node].push_back(nextNode);
                indegree[nextNode]++;
            }
        }

        queue<int> bfsQueue;
        for (int node = 1; node < n; node++) {
            if (indegree[node] == 0) {
                bfsQueue.push(node);
            }
        }

        vector<int> shortestSeq;
        while (!bfsQueue.empty()) {
            if (bfsQueue.size() > 1) {
                return false;
            }
            int currNode = bfsQueue.front();
            bfsQueue.pop();
            shortestSeq.push_back(currNode);

            for (auto neighbor: adj[currNode]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }

        if (shortestSeq.size() != n - 1) {
            return false;
        }

        for (int i = 0; i < shortestSeq.size(); i++) {
            if (org[i] != shortestSeq[i])
                return false;
        }

        return true;
    }
};
