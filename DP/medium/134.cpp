// Runtime: 12 ms, faster than 28.97% of C++ online submissions for Gas Station.
// Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Gas Station.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        int maxSubArrStart = 0;
        int maxSubArrSum = 0;
        int maxStart = 0;
        int maxSum = 0;
        
        int minSubArrStart = 0;
        int minSubArrLen = 0;
        int minSubArrSum = 0;
        int minStart = 0;
        int minLen = 0;
        int minSum = 0;
        
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int newBalance = gas[i] - cost[i];
            sum += newBalance;
            if (maxSubArrSum + newBalance < newBalance) {
                maxSubArrStart = i;
                maxSubArrSum = newBalance;
            } else maxSubArrSum += newBalance;
            
            if (maxSum < maxSubArrSum) {
                maxSum = maxSubArrSum;
                maxStart = maxSubArrStart;
            }
            
            if (minSubArrSum + newBalance > newBalance) {
                minSubArrStart = i;
                minSubArrLen = 1;
                minSubArrSum = newBalance;
            } else {
                minSubArrLen += 1;
                minSubArrSum += newBalance;
            }
            
            if (minSum > minSubArrSum) {
                minSum = minSubArrSum;
                minStart = minSubArrStart;
                minLen = minSubArrLen;
            }
        }
        
        int circleMaxSum = sum - minSum;
        int circleMaxStart = (minStart + minLen) % size;
        if (sum >= 0) {
            if (circleMaxSum > maxSum) {
                return circleMaxStart;
            } else {
                return maxStart;
            }
        } else {
            return -1;
        }
    }
};
