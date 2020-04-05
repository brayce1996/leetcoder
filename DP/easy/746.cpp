// Runtime: 8 ms, faster than 43.24% of C++ online submissions for Min Cost Climbing Stairs.
// Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Min Cost Climbing Stairs.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++) {
            cost[i] = min(cost[i - 2], cost[i - 1]) + cost[i];
        }
        
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
