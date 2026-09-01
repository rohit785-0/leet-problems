class Solution {
public: 
    bool Exists(int idx, string word, vector<vector<char>>&board, int i, int j)    {
        if(idx==word.size())   return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
            || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        bool found = Exists(idx+1,word,board, i + 1, j) ||
                     Exists(idx+1,word,board, i - 1, j) ||
                     Exists(idx+1,word,board, i, j - 1) ||
                     Exists(idx+1,word,board, i, j + 1);
        board[i][j] = temp;             
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)    {

            for(int j=0;j<board[0].size();j++)    {
                if(word[0]==board[i][j] && Exists(0,word,board,i,j))   {
                    return true;
                }
            }
        }

        return false;
    }
};