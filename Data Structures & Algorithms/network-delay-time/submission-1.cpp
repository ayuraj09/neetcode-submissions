class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int> dis(n+1,1e5);
        unordered_map<int,vector<pair<int,int>>> mp;

        for(int i=0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dis[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            if(dis[node[1]]<node[0]) continue;
            for(auto &itr : mp[node[1]]){
                if(dis[itr.first]>dis[node[1]]+itr.second){
                   dis[itr.first] = dis[node[1]]+itr.second;
                   pq.push({dis[itr.first],itr.first});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            ans = max(dis[i],ans);
        }
        if(ans==1e5) return -1;
        return ans;
    }
};
