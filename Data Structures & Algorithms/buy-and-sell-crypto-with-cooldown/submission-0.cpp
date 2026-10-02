class Solution {
public:
    int solve(vector<int>& prices, int idx, int holding,
              vector<vector<int>>& dp) {
        if (idx >= prices.size())
            return 0;

        if (dp[idx][holding] != -1)
            return dp[idx][holding];

        if (holding) {
            // Sell or keep holding
            int sell = prices[idx] + solve(prices, idx + 2, 0, dp);
            int skip = solve(prices, idx + 1, 1, dp);

            return dp[idx][holding] = max(sell, skip);
        } else {
            // Buy or don't buy
            int buy = -prices[idx] + solve(prices, idx + 1, 1, dp);
            int skip = solve(prices, idx + 1, 0, dp);

            return dp[idx][holding] = max(buy, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(prices, 0, 0, dp);
    }
};
