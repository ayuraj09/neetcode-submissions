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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,char>> aa;
        for(auto &it : intervals){
            aa.push_back({it.start,'s'});
            aa.push_back({it.end,'e'});
        }
        sort(aa.begin(),aa.end());
        int ans = 0;
        for(auto &it :aa){
            if(it.second=='e'){
                ans--;
            }else ans++;
            if(ans>1) return 0;
        }
        return 1;
    }
};
