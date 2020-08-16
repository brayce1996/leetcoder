class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) return 0;
        int maxTransNum = prices.size() / 2;
        vector<int> profits(maxTransNum + 1, 0);
        vector<int> bestBuy(maxTransNum + 1, prices[0]);
        
        for (int i = 1; i < prices.size(); i++) {
            for (int k = 1; k <= maxTransNum; k++) {
                // keep updating the minimum of bestbuy at date i for transcation k
                // either current bestBuy is min (former), or a new buy on date i is min (latter)
                bestBuy[k] = min(bestBuy[k], prices[i] - profits[k - 1]);
                
                // either not sell at date i (former), or sell at date i (latter)
                profits[k] = max(profits[k], prices[i] - bestBuy[k]);
            }
        }
        
        
        // take transaction fee into account
        int maxProfitWithFee = 0;
        for (int k = 1; k <= maxTransNum; k++) {
            maxProfitWithFee = max(maxProfitWithFee, profits[k] - k * fee);
        }
        return maxProfitWithFee;
    }
};
