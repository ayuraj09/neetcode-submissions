class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> premul;
        vector<int> sufmul(nums.size());
        sufmul[nums.size()-1] = nums[nums.size()-1];
        premul.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            premul.push_back(nums[i]*premul[i-1]);
            sufmul[nums.size()-i-1]=sufmul[nums.size()-i]*nums[nums.size()-i-1];
        }
        cout<<"\n";
        vector<int> ans(nums.size());
        ans[0] = sufmul[1];
        ans[nums.size()-1] = premul[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            ans[i] = sufmul[i+1]*premul[i-1];
        }
        return ans;
    }
};
