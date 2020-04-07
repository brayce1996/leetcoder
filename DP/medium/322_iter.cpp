// Runtime: 280 ms, faster than 9.80% of C++ online submissions for Coin Change.
// Memory Usage: 10.5 MB, less than 94.12% of C++ online submissions for Coin Change.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> memo(amount + 1, -1);
        int minCoin = 0x7fffffff;
        for (int coin: coins) {
            if (coin <= amount) {
                memo[coin] = 1;
                minCoin = min(coin, minCoin);
            }
        }
        for (int i = minCoin; i <= amount; i++) {
            if (memo[i] != -1) continue;
            int minCharge = 0x7fffffff;
            for (int coin: coins) {
                if (i - coin > 0 && memo[i - coin] != -1) {
                    minCharge = min(minCharge, memo[i - coin] + 1);
                }
            }
            if (minCharge != 0x7fffffff)
                memo[i] = minCharge;
        }
        return memo[amount];
    }
};
