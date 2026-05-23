class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return 0;
        vector<int> frq(26,0);
        for(int i=0;i<s.length();i++){
            frq[s[i]-'a']++;
            frq[t[i]-'a']--;
        }
        for(auto &it : frq){
            if(it!=0) return 0;
        }
        return 1;
    }
};
