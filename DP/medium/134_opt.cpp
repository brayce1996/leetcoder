// Runtime: 4 ms, faster than 98.39% of C++ online submissions for Gas Station.
// Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Gas Station.
// reference: https://leetcode.com/problems/gas-station/discuss/42568/Share-some-of-my-ideas.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int tank = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                sum += tank;
                tank = 0;
            }
        }
        return (sum + tank >= 0)? start : -1;
    }
};