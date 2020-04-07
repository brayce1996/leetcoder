// Runtime: 116 ms, faster than 22.11% of C++ online submissions for Coin Change.
// Memory Usage: 10.8 MB, less than 94.12% of C++ online submissions for Coin Change.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> memo(amount + 1, 0);
        return dfs(coins, amount, memo);
    }
    
    int dfs(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (memo[amount] != 0) return memo[amount];
        
        int minChange = 0x7fffffff;
        for (int i = 0; i < coins.size(); i++) {
            int nextChange = dfs(coins, amount - coins[i], memo);
            if (nextChange >= 0 && nextChange < minChange) {
                minChange = nextChange;
            }
        }
        memo[amount] = (minChange == 0x7fffffff) ? -1 : minChange + 1;
        return memo[amount];
    }
};
