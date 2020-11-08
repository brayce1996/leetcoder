class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> dp(prices.size(), 0);
        int buyWithMaxProf = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            int rest = dp[i-1];
            int sell = prices[i] + buyWithMaxProf;

            if (i-2 < 0) buyWithMaxProf = max(buyWithMaxProf, -prices[i]);
            else buyWithMaxProf = max(buyWithMaxProf, dp[i-2] - prices[i]);

            dp[i] = max(rest, sell);
        }

        return dp.back();
    }
};
