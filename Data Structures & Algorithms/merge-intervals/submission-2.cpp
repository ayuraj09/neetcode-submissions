class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //open -> 0 | close -> 1
        // vector<pair<int,int>> ivr()
        multiset<pair<int,int>> inv;
        for(auto &it : intervals){
            inv.insert({it[0],0});
            inv.insert({it[1],1});
        }
        vector<vector<int>> ans;
        int val = 0;
        vector<int> singleInv;
        for(auto it : inv){
            if(val==0){
                singleInv.push_back(it.first);
            }
            if(it.second == 0){
                val++;
            }else val--;
            if(val==0){
                singleInv.push_back(it.first);
                ans.push_back(singleInv);
                singleInv.clear();
            }
        }
        return ans;
    }
};
