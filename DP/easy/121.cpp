class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int currMax = prices[1] - prices[0];
        int globalMax = prices[1] - prices[0];
        
        for (int i = 1; i < prices.size() - 1; i++) {
            int diff = prices[i + 1] - prices[i];
            currMax = max(currMax + diff, diff);
            globalMax = max(globalMax, currMax);
        }
        
        return max(globalMax, 0);
    }
};
