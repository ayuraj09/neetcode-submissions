class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0,r = l+1;
        int ans = 0;
        while(r<h.size()){
            int temp = 0;
            while(r<h.size() && h[r]<h[l]){
                temp+=(h[l]-h[r]);
                r++;
            }
            if(r<h.size() && h[r]>=h[l]){
                l=r;
                ans+=temp;
            }
            r++;
            cout<<temp<<" ";
        }
        r=h.size()-1;
        l=r-1;

        while(l>=0){
            int temp = 0;
            while(l>=0 && h[l]<=h[r]){
                temp+=(h[r]-h[l]);
                l--;
            }
            if(l>=0 && h[l]>h[r]){
                r=l;
                ans+=temp;
            }
            l--;
            // cout<<temp<<" ";
        }
        return ans;
    }
};
