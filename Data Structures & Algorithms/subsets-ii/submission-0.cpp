class Solution {
public:

    void helper(vector<int>& nums, int idx, vector<vector<int>> &ans, vector<int> &temp){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(nums,idx+1,ans, temp);
        temp.pop_back();
        while(idx+1<nums.size() && nums[idx+1]==nums[idx])idx++;
        helper(nums,idx+1,ans, temp);
    } 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(nums,0, ans,temp);
        return ans;
    }
};
