class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            
            // holding = 1
            int sell = prices[idx] + dp[idx + 2][0];
            int skip = dp[idx + 1][1];

            dp[idx][1] = max(sell, skip);

            // holding = 0
            int buy = -prices[idx] + dp[idx + 1][1];
            skip = dp[idx + 1][0];

            dp[idx][0] = max(buy, skip);
        }

        return dp[0][0];
    }
};
