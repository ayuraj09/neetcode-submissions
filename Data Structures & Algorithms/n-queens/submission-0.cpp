class Solution {
public:

    void initialise(vector<string> &temp, int &n){
        string s = "";
        for(int i=0;i<n;i++){
            s +=".";
        }
        for(int i=0;i<n;i++){
            temp[i] = s;
        }
    }

    bool check(vector<string> &temp, int &idx, int &jdx, int &n){

        if(idx == 0)
            return 0;

        // Check all previous rows
        for(int i = idx - 1; i >= 0; i--){

            int diff = idx - i;

            // Same column
            if(temp[i][jdx] == 'Q')
                return 1;

            // Left diagonal
            if(jdx - diff >= 0 && temp[i][jdx - diff] == 'Q')
                return 1;

            // Right diagonal
            if(jdx + diff < n && temp[i][jdx + diff] == 'Q')
                return 1;
        }

        return 0;
    }


    void solve(int n, vector<string> &temp, int idx, int jdx, vector<vector<string>> &ans){
        if(idx>=n){
            ans.push_back(temp);
            for(auto it: temp){
                cout<<it<<"\n";
            }
            return;
        }

        for(int i = 0; i<n; i++){
            if( check(temp,idx,i,n)==0){               
                temp[idx][i]='Q';
                solve(n,temp,idx+1,i,ans);
                temp[idx][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        initialise(temp,n);
        solve(n,temp,0,0, ans);
        return ans;
        
    }
};
