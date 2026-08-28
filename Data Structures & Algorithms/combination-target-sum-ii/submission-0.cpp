class Solution {
public:


      void helper(vector<int>& nums, int idx, vector<vector<int>> &ans, vector<int> &temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

        if(idx>=nums.size()){
            return;
        }

        temp.push_back(nums[idx]);
        if(target>=nums[idx]) //optimisation
            helper(nums,idx+1,ans, temp, target-nums[idx]);
        temp.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1])
            idx++;

        helper(nums, idx+1, ans, temp, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,0, ans,temp,target);
        return ans;   
    }
};
