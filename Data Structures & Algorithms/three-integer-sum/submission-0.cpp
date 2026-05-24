class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        set<vector<int>> tempSet;
        for(int i=0;i<=nums.size()-3;i++){
            map<int,int> mp;
            for(int j=i+1;j<nums.size();j++){
                if(mp.find(target-nums[i]-nums[j])==mp.end()){
                    mp[nums[j]] = j;
                }else {
                    vector<int> temp = {nums[i],(target-nums[i]-nums[j]),nums[j]};
                    sort(temp.begin(),temp.end());
                    tempSet.insert(temp);
                }
            }
        }
        vector<vector<int>> ans;
        for(auto &it:tempSet){
            ans.push_back(it);
        }
        return ans; 
    }
};
