class Solution {
public:

    int climbStairs(int n) {
        if(n<3) return n;
        vector<int> ans(n+1,0);
        ans[2]=2;
        ans[1]=1;

        for(int i=3;i<=n;i++){
            ans[i] = ans[i-1] + ans[i-2];
        }
        return ans[n];
    }
};
