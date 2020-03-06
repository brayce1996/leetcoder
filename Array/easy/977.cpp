// start from middlem O(n)
// Runtime: 164 ms, faster than 7.91% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 13.5 MB, less than 86.49% of C++ online submissions for Squares of a Sorted Array.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int size = A.size();
        vector<int> result;
        int left = -1, right = 0x7fffffff;
        for (int i = 0; i < size; i++) {
            if (A[i] >= 0){
                right = i;
                left = i - 1;
                break;
            }
        }
        
        if (right == 0x7fffffff) left = size - 1;
        
        while(left >= 0 || right < size) {
            cout << left << " " << right << endl;
            if (left < 0) {
                result.push_back(A[right] * A[right]);
                right++;
            } else if (right >= size) {
                result.push_back(A[left] * A[left]);
                left--;
            } else {
                int leftVal = A[left] * A[left];
                int rightVal = A[right] * A[right];
                if (leftVal > rightVal) {
                    result.push_back(rightVal);
                    right++;
                } else {
                    result.push_back(leftVal);
                    left--;
                }
            }
        }
        
        return result;
    }
};
