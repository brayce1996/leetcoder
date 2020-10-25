class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());

        for (auto edge: edges) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        unordered_set<int> unvisited;
        for (int i = 0; i < n; i++) {
            unvisited.insert(i);
        }

        int groupCount = 0;
        while (!unvisited.empty()) {
            int start = *(unvisited.begin());
            dfs(adj, unvisited, start);
            groupCount++;
        }
        return groupCount;
    }

    void dfs(vector<vector<int>> &adj, unordered_set<int> &unvisited, int currNode) {
        unvisited.erase(currNode);
        for (auto neighbor: adj[currNode]) {
            if (unvisited.find(neighbor) != unvisited.end()) {
                dfs(adj, unvisited, neighbor);
            }
        }
    }
};
