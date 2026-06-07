class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        vector<pair<int,int>> vp;

        for(int i = 0; i < speed.size(); i++) {
            vp.push_back({pos[i], speed[i]});
        }

        sort(vp.begin(), vp.end());

        int n = vp.size();

        double lastTime =
            (double)(target - vp[n - 1].first) / vp[n - 1].second;

        int ans = n;

        for(int i = n - 2; i >= 0; i--) {

            double time =
                (double)(target - vp[i].first) / vp[i].second;

            if(time <= lastTime) {
                ans--;
            } else {
                lastTime = time;
            }
        }

        return ans;
    }
};