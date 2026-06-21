class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<bool> &used, vector<int> &temp){
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!used[nums[i]+10]){
                temp.push_back(nums[i]);
                used[nums[i]+10]=1;
                solve(ans,nums,used,temp);
                temp.pop_back();
                used[nums[i]+10]=0;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
       vector<bool> used(21,0);
       
       vector<vector<int>> ans;
        vector<int> temp;
       solve(ans,nums,used,temp);
       return ans;
    }
};
