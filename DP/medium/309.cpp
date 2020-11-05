class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);

        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN;

        for (int i = 1; i < prices.size(); i++) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s0[i-1] - prices[i], s1[i-1]);
            s2[i] = s1[i-1] + prices[i];
        }


        return max3(s0.back(), s1.back(), s2.back());
    }

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }
};i
