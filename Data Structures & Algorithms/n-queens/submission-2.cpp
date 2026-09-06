class Solution {
public:

    void initialise(vector<string> &temp, int &n) {
        string s = "";

        for(int i = 0; i < n; i++) {
            s += ".";
        }

        for(int i = 0; i < n; i++) {
            temp[i] = s;
        }
    }

    void solve(vector<bool> &col,
               vector<bool> &diag1,
               vector<bool> &diag2,
               int n,
               vector<string> &temp,
               int idx,
               vector<vector<string>> &ans) {

        // All rows filled
        if(idx >= n) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++) {

            // Check column and both diagonals
            if(col[i] == 0 &&
               diag1[idx - i + n - 1] == 0 &&
               diag2[idx + i] == 0) {

                // Place queen
                temp[idx][i] = 'Q';

                col[i] = 1;
                diag1[idx - i + n - 1] = 1;
                diag2[idx + i] = 1;

                // Move to next row
                solve(col, diag1, diag2,
                      n, temp, idx + 1, ans);

                // Backtrack
                temp[idx][i] = '.';

                col[i] = 0;
                diag1[idx - i + n - 1] = 0;
                diag2[idx + i] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<bool> col(n, 0);

        // There are 2*n-1 diagonals of each type
        vector<bool> diag1(2 * n - 1, 0);
        vector<bool> diag2(2 * n - 1, 0);

        vector<string> temp(n);

        initialise(temp, n);

        solve(col, diag1, diag2,
              n, temp, 0, ans);

        return ans;
    }
};