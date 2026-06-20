class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return 0;
        map<char,int> s1f;
        for(int i=0;i<s1.length();i++){
            s1f[s1[i]]++;
        }
        map<char,int>s21f; 
        int r = 0; 
        for(r=0;r<s1.length();r++){
            s21f[s2[r]]++;
        }
        int l=0;
        while(r<s2.length()){
            if(s1f==s21f) return 1;
            s21f[s2[r]]++;
            s21f[s2[l++]]--;
            if(s21f[s2[l-1]]==0) s21f.erase(s2[l-1]);
            r++;
        }
        return s1f==s21f;
    }
};
