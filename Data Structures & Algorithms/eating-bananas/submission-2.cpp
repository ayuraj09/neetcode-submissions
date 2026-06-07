class Solution {
public:

    bool ableToEat(int &mid, vector<int>& piles, int &h){
        int reqTime = 0;
        for(auto &it : piles){ 
            reqTime+=(it + mid - 1) / mid;
        }
        return reqTime<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i=0;i<piles.size();i++){
            r = max(piles[i],r);
        }
        int ans = r;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(ableToEat(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
};
