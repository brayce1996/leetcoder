class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        queue<int> bfsQueue;
        vector<int> attendOrder;
        
        for (auto edge: prerequisites) {
            G[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
        }
        
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 0) bfsQueue.push(i);
        }
        
        while(!bfsQueue.empty()) {
            int curr = bfsQueue.front();
            bfsQueue.pop();
            attendOrder.push_back(curr);
            
            for (int neighbor: G[curr]) {
                degree[neighbor]--;
                if (degree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return (attendOrder.size() == numCourses)? attendOrder : vector<int>();
    }
};
