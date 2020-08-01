class Node {
public:
    
    // stores the longest increasing path by going this direction 
    vector<bool> canVisit; // left, up, right, down
    
    // stores the max path length of the four direction
    int maxPath = -1; // mark as unassigned value
    
    Node(bool left, bool up, bool right, bool down) {
        canVisit.push_back(left);
        canVisit.push_back(up);
        canVisit.push_back(right);
        canVisit.push_back(down);
    }
};

class Solution {
public:
    int dirDelta[4][2] {
        {0, -1},
        {-1, 0},
        {0, 1},
        {1, 0},
    };
        
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        
        vector<vector<Node*>> incGraph;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        // build a 2D graph that recording increase edges(paths)
        for (int row = 0; row < rowSize; row += 1) {
            vector<Node*> newRow;
            for (int col = 0; col < colSize; col += 1) {
                Node *node = new Node(
                    col > 0 && matrix[row][col] > matrix[row][col - 1],
                    row > 0 && matrix[row][col] > matrix[row - 1][col],
                    col < colSize - 1 && matrix[row][col] > matrix[row][col + 1],
                    row < rowSize - 1 && matrix[row][col] > matrix[row + 1][col]
                );
                newRow.push_back(node);
            }
            incGraph.push_back(newRow);
        }
        
        
        int longesIncPath = 0;
        for (int row = 0; row < rowSize; row += 1) {
            for (int col = 0; col < colSize; col += 1) {
                longesIncPath = max(longesIncPath, dfs(incGraph, row, col));
            }
        }
        return longesIncPath;
    }
    
    int dfs(vector<vector<Node*>> &incGraph, int row, int col) {
        Node *node = incGraph[row][col];
        
        // if this node has visited before, return memorized maxPath
        if (node->maxPath >= 0)
            return node->maxPath;
        
        for (int dirIndex = 0; dirIndex < node->canVisit.size(); dirIndex++) {
            // try to visit the four dirction if they are available to visit
            if (node->canVisit[dirIndex]) {
                int nextRow = dirDelta[dirIndex][0] + row;
                int nextCol = dirDelta[dirIndex][1] + col;
                node->maxPath = max(node->maxPath, dfs(incGraph, nextRow, nextCol) + 1);
            }
        }
        
        // none of the four dirction is available, then this node's maxPath is one (count itself as 1)
        if (node->maxPath == -1) {
            node->maxPath = 1;
        }
        
        return node->maxPath;
    }
};
