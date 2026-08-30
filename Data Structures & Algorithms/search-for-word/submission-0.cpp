class Solution {
public:

    bool check(vector<vector<char>>& board, string &word, int idx, int jdx, int step, vector<vector<bool>> &vis){
        if(idx<0 || idx>=board.size() || jdx<0 || jdx>=board[0].size() || vis[idx][jdx]==1){
            return 0;
        }
        if(word[step] == board[idx][jdx] && step+1==word.length()){
            return 1;
        }
        vis[idx][jdx]=1;
        bool ans = 0;
        if(word[step] == board[idx][jdx]){
           ans = 
            check(board,word,idx+1,jdx,step+1,vis)||
            check(board,word,idx,jdx+1,step+1,vis)||
            check(board,word,idx,jdx-1,step+1,vis)||
            check(board,word,idx-1,jdx,step+1,vis);
                
        }
        vis[idx][jdx]=0;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size()+1,vector<bool> (board[0].size()+1,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    if(check(board,word,i,j,0,vis))
                        return 1;
                }
            }
        }
        return 0;
    }
};
