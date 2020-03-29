// Runtime: 4 ms, faster than 97.70% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int currMin = prices[0];
        int maxDiff = 0;
        for (int i = 1; i < prices.size(); i++) {
            currMin = min(currMin, prices[i]);
            maxDiff = max(maxDiff, prices[i] - currMin);
        }
        
        return maxDiff;
    }
};
