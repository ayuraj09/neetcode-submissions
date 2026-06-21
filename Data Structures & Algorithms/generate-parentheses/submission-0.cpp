class Solution {
public:
    int size;
    void solve(int n, set<string> &ans, string &temp, int open){
        if(temp.size()==2*size){
            ans.insert(temp);
            return;
        }

        if(open>0){
            if(n>0){
                temp.push_back('(');
                solve(n-1,ans,temp,open+1);
                temp.pop_back();
            }
            temp.push_back(')');
            solve(n,ans,temp,open-1);
            temp.pop_back();
        }
        if(n>0){
            temp.push_back('(');
            solve(n-1,ans,temp,open+1);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        set<string> ans;
        string temp;
        size = n;
        solve(n,ans,temp,0);
        vector<string> af;
        for(auto &it : ans){
            af.push_back(it);
        }
        return af;
    }
};
