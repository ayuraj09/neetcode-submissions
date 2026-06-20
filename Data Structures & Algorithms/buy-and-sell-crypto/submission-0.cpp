class Solution {
public:
    int maxProfit(vector<int>& p) {
     int mn = INT_MAX;
     int ans = INT_MIN;
        for(int i=0;i<p.size();i++){
            mn = min(mn,p[i]);
            ans = max(p[i]-mn,ans);
        }
        return ans;
    }
};
