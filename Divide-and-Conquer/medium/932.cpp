// Runtime: 8 ms, faster than 85.85% of C++ online submissions for Beautiful Array.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Beautiful Array.

// 1. [odd] [even], split odd and even parts

// 2. Addition
// A[k] * 2 != A[i] + A[j]
// (A[k] + x) * 2 = A[k] * 2 + 2x != A[i] + A[j] + 2x = (A[i] + x) + (A[j] + x)
// [1,3,2] => [2,4,3]

// 3. Multiplication
// A[k] * 2 != A[i] + A[j]
// A[k] * x * 2 = (A[k] * 2) * x != (A[i] + A[j]) * x = A[i] * x +  A[j] * x
// [1,3,2] => [2,6,4]

// 1. + 2. + 3.:
// [1] => [1]  [2] => [1, 2]
// [1, 2] => [1, 3]  [2, 4] => [1, 3, 2, 4]
// [1,3,2,4] => [1,5,3,7]  [2,6,4,8] => [1,5,3,7,2,6,4,8]

// Time complexity:
//   The while loop combined with for loop time:
//   1 + 2 + 4 + 8 + 16 + ... + n
//   = (1 - 2^(logn - 1)) / (1 - 2)
//   ~= (1 - 2^logn) / (1 - 2)
//   = (1 - n) / (1 - 2)
//   = O(n)

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result({1});
        while(result.size() < N) {
            vector<int> newResult;
            
            // odd part
            for (int r: result) {
                if (r * 2 - 1 <= N) newResult.push_back(r * 2 - 1);
            }
            
            // even part
            for (int r: result) {
                if (r * 2 <= N) newResult.push_back(r * 2);
            }
            
            result = newResult;
        }
        return result;
    }
};
