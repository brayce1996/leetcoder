// Runtime: 48 ms, faster than 23.22% of C++ online submissions for Course Schedule.
// Memory Usage: 13.5 MB, less than 89.09% of C++ online submissions for Course Schedule.

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edgeTable(numCourses, vector<int>(0));
        vector<bool> startVertex(numCourses, true);
        vector<bool> isReached(numCourses, false);
        unordered_set<int> reachStack;
        
        for (auto edge: prerequisites) {
            edgeTable[edge[1]].push_back(edge[0]);
            startVertex[edge[0]] = false;
        }
        
        bool hasLoop = false;
        for (int i = 0; i < numCourses; i++) {
            if (startVertex[i]) {
                hasLoop = dfsFindLoop(edgeTable, i, reachStack, isReached);
                if (hasLoop) {
                    return false;
                }
            }
        }
        
        for (auto reach: isReached) {
            if (!reach) return false;
        }
        
        return true;
    }
    
    bool dfsFindLoop(vector<vector<int>>& edgeTable, int vertex, unordered_set<int>& reachStack, vector<bool>& isReached) {
        isReached[vertex] = true;
        if (reachStack.find(vertex) != reachStack.end()) {
            return true;
        }
        
        if(edgeTable[vertex].empty()) {
            return false;
        }
        
        bool hasLoop = false;
        reachStack.insert(vertex);
        for (auto nextVertex: edgeTable[vertex]) {
            hasLoop = dfsFindLoop(edgeTable, nextVertex, reachStack, isReached);
            if (hasLoop) return true;
        }
        reachStack.erase(vertex);
        
        return false;
    }
};
