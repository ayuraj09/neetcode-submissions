class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> mp;

        for(auto &f : flights){
            mp[f[0]].push_back({f[1], f[2]});
        }

        vector<vector<int>> dis(n, vector<int>(k + 2, 1e9));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // {cost, node, stops}
        pq.push({0, src, 0});
        dis[src][0] = 0;

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int cost  = cur[0];
            int node  = cur[1];
            int stops = cur[2];

            if(node == dst)
                return cost;

            if(stops == k + 1)
                continue;

            for(auto &nbr : mp[node]){

                int nextNode = nbr.first;
                int nextCost = cost + nbr.second;

                if(nextCost < dis[nextNode][stops + 1]){

                    dis[nextNode][stops + 1] = nextCost;

                    pq.push({
                        nextCost,
                        nextNode,
                        stops + 1
                    });
                }
            }
        }

        return -1;
    }
};