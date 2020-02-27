// refering the comment in this post: https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170857/One-stack-solution
// That's a very good idea. We don't have to calculate left and right separately in two passes. The fact is that, if A[i] pops A[idx] out, then A[i] is the nearest larger element on the right of A[idx]. So we can calculate the answer for the elements that are being poped out, instead of the element that is being pushed in. -- Zhanghuimeng

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int size = A.size();
        vector<int> prevLessIndex(size, -1);
        vector<int> nextLessIndex(size, size);
        stack<int> incStack;
        
        for (int i = 0; i < size; i++) {
            
            while(!incStack.empty() && A[incStack.top()] > A[i]) {
                int x = incStack.top();
                incStack.pop();
                nextLessIndex[x] = i;
            }
            
            prevLessIndex[i] = (incStack.empty()) ? -1 : incStack.top();
            incStack.push(i);
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
