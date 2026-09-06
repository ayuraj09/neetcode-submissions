class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n+1,INT_MAX);
        ans[0]=cost[0];
        ans[1] = cost[1];
        cost.push_back(0);
        for(int i=2;i<=n;i++){
            ans[i]=cost[i] + min(ans[i-1],ans[i-2]);
        }
        return ans[n];
    }
};
