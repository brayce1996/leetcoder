// reference: https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int size = A.size();
        vector<int> prevLessIndex(size, -1);
        vector<int> nextLessIndex(size, size);
        
        stack<int> prevIncStack;
        stack<int> nextIncStack;
        
        for (int i = 0; i < size; i++) {
            while(!prevIncStack.empty() && A[prevIncStack.top()] > A[i]) {
                prevIncStack.pop();
            }
            prevLessIndex[i] = (prevIncStack.empty()) ? -1 : prevIncStack.top();
            prevIncStack.push(i);
            
            while(!nextIncStack.empty() && A[nextIncStack.top()] > A[i]) {
                int x = nextIncStack.top();
                nextIncStack.pop();
                nextLessIndex[x] = i;
            }
            nextIncStack.push(i);
        }
        
        int sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < size; i++) {
            int leftDist = i - prevLessIndex[i];
            int rightDist = nextLessIndex[i] - i;
            sum = (sum + (A[i] * leftDist * rightDist) % mod) % mod;
        }
        return sum;
    }
};
