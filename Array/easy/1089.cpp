// Runtime: 16 ms, faster than 97.51% of C++ online submissions for Duplicate Zeros.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeroCount = 0;
        int currLen = 0;
        for (int i = 0; i + zeroCount < arr.size(); i++) {
            currLen += 1;
            if (arr[i] == 0) {
                zeroCount++;
                currLen += 1;
            }
        }
        int backIndex = arr.size() - 1;
        if (currLen > arr.size()) { // [0101] -> [0010],[01]
            arr[backIndex] = 0;
            backIndex--;
            zeroCount--;
        }
        
        for (int i = backIndex; i >= 0 && zeroCount > 0; i--) {
            if (arr[i - zeroCount] == 0) {
                arr[i] = 0;
                arr[i - 1] = 0;
                i--;
                zeroCount--;
            } else arr[i] = arr[i - zeroCount];
        }
    }
};

