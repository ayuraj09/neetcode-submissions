class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<long long,vector<int>>> s;
        for(auto & it : points){
            s.insert({1LL*it[0]*it[0] +1LL* it[1]*it[1],it});
        }
        vector<vector<int>> ans;
        for(auto &it : s){
            ans.push_back(it.second);
            if(ans.size()==k) return ans;
        }
        return ans;
    }
};
