class Solution {
public:

    bool isExist(vector<int> &fs, vector<int> &ft){
        for(int i=0;i<256;i++){
            if(fs[i]<ft[i]) return 0;
        }
        return 1;
    }

    string minWindow(string s, string t) {
        
        if(s.length() < t.length()) return "";

        vector<int> ft(256,0);
        vector<int> fs(256,0);
        
        for(int i=0;i<t.length();i++){
            ft[t[i]]++;
        }

        int r = 0, l = 0, minl = INT_MAX ;
        pair<int,int> ans = {-1,-1};
        
        while(r<t.length()-1){
            fs[s[r]]++;
            r++;
        }

        for(;r<s.length();r++){
            if(r<s.length())
                fs[s[r]]++;

            while(isExist(fs,ft)){
                if(minl>r-l+1){
                    ans = {l,r};
                    minl = min(minl,r-l+1);
                }
                fs[s[l]]--;
                l++;
                if(fs[s[l-1]]<ft[s[l-1]]) break;
            }
        }
        if(minl==INT_MAX)return "";
        return s.substr(ans.first,minl);
       
    }
};
