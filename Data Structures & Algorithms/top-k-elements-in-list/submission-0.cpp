class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> frq;
        map<int,int> mp;
        for(auto &it:nums){
            mp[it]++;
        }
        for(auto &it : mp){
            frq.push_back({it.second,it.first});
        }
        sort(frq.rbegin(),frq.rend());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(frq[i].second);
        }
        return ans;
    }
};
