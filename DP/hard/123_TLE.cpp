// cut this problem into smaller problem:
// find one transcation max profit at two different part (left and right)
// then sum them up to gain two transcation max profit

// however, this solution takes O(n^2). it's too slow and cannot pass TLE testcase.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            int left = oneTrasMaxProfit(prices, 0, i);
            int right = oneTrasMaxProfit(prices, i, prices.size() - 1);
            profit = max(profit, left + right);
        }
        
        return profit;
    }
    
    
    int oneTrasMaxProfit(vector<int>& prices, int start, int end) {
        if (end - start < 1) return 0;
        
        int profit = 0;
        int buyPrice = prices[start];
        
        for (int i = start + 1; i <= end; i += 1) {
            profit = max(profit, prices[i] - buyPrice);
            buyPrice = min(buyPrice, prices[i]);
        }
        
        return profit;
    }
};
