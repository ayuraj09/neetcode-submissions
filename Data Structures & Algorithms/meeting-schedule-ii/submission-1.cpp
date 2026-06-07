/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& in) {
        vector<pair<int,char>> vp;
        for(int i=0;i<in.size();i++){
            vp.push_back({in[i].start,'s'});
            vp.push_back({in[i].end,'e'});
        }
        sort(vp.begin(),vp.end());
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<vp.size();i++){
            if(vp[i].second=='s'){
                cnt++;
                ans = max(cnt,ans);
            }else cnt--;
        }
        return ans;
    }
};
