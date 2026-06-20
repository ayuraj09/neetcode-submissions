class Solution {
public:

    vector<string> solve(string &digits, unordered_map<char,string> &mp, string temp, vector<string> &ans, int idx){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
        }
        if(idx>=digits.size()){
            return ans;
        }
        for(auto &it : mp[digits[idx]]){
            solve(digits,mp,temp+it,ans,idx+1);
        }
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        return solve(digits,mp,"",ans,0);
        return ans;
    }
};
