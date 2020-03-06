// start from A[0] and A[size - 1] O(n)
// Runtime: 88 ms, faster than 98.96% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 12.8 MB, less than 100.00% of C++ online submissions for Squares of a Sorted Array.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        int left = 0, right = size - 1;
        vector<int> ans(size, 0);
        
        for (int i = size - 1; i >= 0; i--) {
            if (abs(A[left]) > abs(A[right])) {
                ans[i] = A[left] * A[left];
                left++;
            } else {
                ans[i] = A[right] * A[right];
                right--;
            }
        }
        return ans;
    }
};
