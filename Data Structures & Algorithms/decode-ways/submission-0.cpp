class Solution {
public:

    int solve(string &s, int idx, vector<int> &dp){
        if(idx>=s.length()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int use1 = solve(s,idx+1,dp);
        int use2 = 0;
        if(idx+1 < s.length()){
            if((s[idx]=='1' && s[idx+1]<='9' && s[idx+1]>='0')||(s[idx]=='2' && s[idx+1]<='6' && s[idx+1]>='0')){
                use2 = solve(s,idx+2,dp);
            }
        }
        return dp[idx] =  use1 + use2;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return solve(s,0,dp);
    }
};

