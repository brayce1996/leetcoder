// reference: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/301357/Java-0ms-(added-Python-and-C%2B%2B)%3A-Easy-to-understand-solutions-using-Heap-and-Binary-Search

// Runtime: 68 ms, faster than 74.25% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage: 13.2 MB, less than 85.18% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int lessEqualThanMid = matrix[0][0];
            int greaterThanMid = matrix[n - 1][n - 1];
            int lessEqualNum = countLessEqual(matrix, mid, lessEqualThanMid, greaterThanMid);
            
            if (lessEqualNum >= k) {
                high = lessEqualThanMid;
            } else {
                low = greaterThanMid;
            }
        }
        
        return high;
    }
    
private:
    int countLessEqual(vector<vector<int>>& matrix, int target, int &less, int &greater) {
        int n = matrix.size();
        int row = n - 1;
        int col = 0;
        
        int count = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] > target) {
                greater = min(greater, matrix[row][col]);
                row--;
            } else {
                less = max(less, matrix[row][col]);
                count += row + 1;
                col++;
            }
        }
        return count;
    }
};