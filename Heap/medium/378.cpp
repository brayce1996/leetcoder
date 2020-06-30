class HeapNode {
// reference: http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
public:
    int row;
    int col;
    int val;
    
    HeapNode(int row, int col, int val): row(row), col(col), val(val) {}
};

bool operator > (const HeapNode &lval, const HeapNode &rval) {
    return lval.val > rval.val;
}
bool operator < (const HeapNode &lval, const HeapNode &rval) {
    return lval.val < rval.val;
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<HeapNode, vector<HeapNode>, greater<vector<HeapNode>::value_type>> minHeap;
        
        // time: O(N), space: O(N)
        for (int row = 0; row < n; row++) {
            HeapNode node(row, 0, matrix[row][0]);
            minHeap.push(node);
        }
        
        // time: O(KlogN), space: O(K)
        for (int count = 0; count < k - 1; count++) {
            // get the min
            HeapNode minNode = minHeap.top();
            minHeap.pop();
            
            if (minNode.col >= n - 1)
                continue;
            
            // move right
            minNode.col++;
            minNode.val = matrix[minNode.row][minNode.col];
            
            // push back
            minHeap.push(minNode);
        }
        
        return minHeap.top().val;
    }
};
