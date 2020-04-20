class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        queue<int> bfsQueue;
        int attendedCourseCount = 0;
        
        for (auto edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
        }
        
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i] == 0) bfsQueue.push(i);
        }
        
        while(!bfsQueue.empty()) {
            int curr = bfsQueue.front();
            bfsQueue.pop();
            attendedCourseCount++;
            
            // remove curr --> decrease degree of curr's adj
            for (auto neighbor: adj[curr]) {
                degree[neighbor]--;
                if (degree[neighbor] == 0) {
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return (attendedCourseCount == numCourses);
    }
};
