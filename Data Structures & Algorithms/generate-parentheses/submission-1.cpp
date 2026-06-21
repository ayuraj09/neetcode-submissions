class Solution {
public:
    int size;
    void solve(int n, vector<string> &ans, string &temp, int open){
        if(temp.size()==2*size){
            ans.push_back(temp);
            return;
        }

        if(n>0 && open==0){
            temp.push_back('(');
            solve(n-1,ans,temp,open+1);
            temp.pop_back();
        }
        else if(open>0){
            if(n>0){
                temp.push_back('(');
                solve(n-1,ans,temp,open+1);
                temp.pop_back();
            }
            temp.push_back(')');
            solve(n,ans,temp,open-1);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        size = n;
        solve(n,ans,temp,0);
        return ans;
    }
};
