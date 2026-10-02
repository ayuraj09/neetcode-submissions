class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxp = nums[0];
        int mxn = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size();i++){
            int oldp = mxp, oldn = mxn;
            mxp = max({nums[i],(nums[i]*oldp),(nums[i]*oldn)});
            mxn = min({nums[i],(nums[i]*oldp),(nums[i]*oldn)});
            ans = max(ans,mxp);
        }

        return ans;
    }
};
