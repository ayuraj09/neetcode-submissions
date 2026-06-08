class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preRq) {
        unordered_map<int,vector<int>> mp;
        vector<int> ind(numCourses,0);
        for(auto &it : preRq){
            mp[it[1]].push_back(it[0]);
            ind[it[0]]++;
        }

        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(ind[i]==0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            // cout<<node<<" ";
            q.pop();
            ans.push_back(node);
                for(auto &it : mp[node]){
                    ind[it]--;
                    if(ind[it]==0){
                        q.push(it);
                    }
                }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};

