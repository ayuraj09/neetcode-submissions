class Solution {
public:
    int characterReplacement(string s, int k) {
     int ans = 0;
        for(char i = 'A'; i<='Z'; i++){
            int t = k;
            int st = 0;
            for(int j=st; j<s.length(); j++){
                if((s[j] != i && t>=0)){
                    t--;
                }
                while(st<=j && t<0){
                    if(s[st] != i){
                        t++;
                    }
                    st++;
                }
                ans = max(ans,j-st+1);
            }
        }

        return ans;
    }
};
