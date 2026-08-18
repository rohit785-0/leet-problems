class Solution {
public:
    bool attacks(vector<string> &board, int i, int j)  {
        int n = board.size();
        // for ith row till j 
        for(int k=0; k<j; k++)  {
            if(board[i][k]=='Q')  return true;
        }
        // for jth column till i
        for(int k=0; k<i; k++)  {
            if(board[k][j]=='Q')  return true;
        }
        //  left uppar and bottom diagonal
        for(int k=0; k<n; k++) {
            if(0<=i+k && 0<=j-k && i+k<n && j-k<n && board[i+k][j-k]=='Q')  return true;  
            if(0<=i-k && 0<=j-k && i-k<n && j-k<n && board[i-k][j-k]=='Q')  return true;  
        }

        return false;
    }

    void nQueen(int col, vector<string> &board, vector<vector<string>> &ans)   {
        if(col==board.size()) {
            ans.push_back(board);
            return;
        }    
        for(int i=0; i<board.size(); i++)  {
            if(!attacks(board,i,col))    {
                board[i][col] = 'Q';
                nQueen(col+1,board,ans);
                board[i][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>>ans;
        nQueen(0,board,ans);
        return ans;
    }
};