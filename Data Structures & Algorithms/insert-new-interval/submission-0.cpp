class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
         vector<pair<int,char>> vp;
            for(auto &it : in){
                vp.push_back({it[0],'e'});
                vp.push_back({it[1],'s'});
            }
            vp.push_back({newIn[0],'e'});
            vp.push_back({newIn[1],'s'});
            sort(vp.begin(),vp.end());
            vector<vector<int>> ans;

            for(int i=0;i<vp.size();){
                vector<int> temp;
                temp.push_back(vp[i].first);
                int cnt = 1;
                i++;
                while(i<vp.size() && (cnt!=0 || vp[i].first == vp[i-1].first)){
                    if(vp[i].second=='s') cnt--;
                    else cnt++; 
                    i++;
                }
                temp.push_back(vp[i-1].first);
                ans.push_back(temp);
            }
        return ans;
    }
};
