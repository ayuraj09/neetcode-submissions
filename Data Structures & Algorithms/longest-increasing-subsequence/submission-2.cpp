class Solution {
public:

    int solve(vector<int>& nums, int idx, int prevIdx, vector<vector<int>> &dp){

        if(idx>=nums.size()) return 0;

        if(dp[idx][prevIdx+1]!=-1){
            return dp[idx][prevIdx+1];
        }
        int inc = 0;
        int exc = 0;
        if(prevIdx!=-1){
            if(nums[prevIdx]<nums[idx]){
                inc = 1 + solve(nums,idx+1, idx, dp);
            }
            exc = solve(nums,idx+1,prevIdx, dp);

        }else{
            inc = 1 + solve(nums,idx+1,idx, dp);
            exc = solve(nums,idx+1,prevIdx, dp);
        }
        return dp[idx][prevIdx+1] = max(inc,exc);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums, 0, -1, dp);
    }
};
