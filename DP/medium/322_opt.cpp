// Runtime: 68 ms, faster than 47.97% of C++ online submissions for Coin Change.
// Memory Usage: 10.4 MB, less than 94.12% of C++ online submissions for Coin Change.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> memo(amount + 1, amount + 1);
        
        for (int coin: coins) {
            for (int i = coin; i <= amount; i++) {
                if (i == coin) memo[i] = 1;
                else if (i > coin) {
                    memo[i] = min(memo[i - coin] + 1, memo[i]);
                }
            }
        }
        return (memo[amount] > amount)? -1 : memo[amount];
    }
};
