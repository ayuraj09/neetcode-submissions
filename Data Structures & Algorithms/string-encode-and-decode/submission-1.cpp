class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto &it: strs){
            s+=it;
            s+="/*-+/";
        }
        return s;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        for(int i=0;i<s.length();i++){
            if((i+4)<s.length() && s[i]=='/' && s[i+1]=='*' && s[i+2] =='-' && s[i+3] =='+' && s[i+4] =='/'){
                i+=4;
                ans.push_back(temp);
                temp="";
                continue;
            }
            temp+=s[i];
        }
        return ans;
    }
};
