class Solution {
public:

    bool srch(vector<vector<char>>& board, string& word, int x, int r, int c,int m, int n)
    {
        if(x==word.length()) return true;
        if(r<0||c<0||r==m||c==n||board[r][c]=='!'||board[r][c]!=word[x]) return false;
        char p=board[r][c];
        board[r][c]='!';
        bool top=srch(board,word,x+1,r-1,c,m,n);
        bool bot=srch(board,word,x+1,r+1,c,m,n);
        bool lef=srch(board,word,x+1,r,c-1,m,n);
        bool rig=srch(board,word,x+1,r,c+1,m,n);
        board[r][c]=p;
        return top||bot||lef||rig;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n=board[0].size(),x=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(srch(board, word, x, i,j,m,n)&&board[i][j]==word[x]) return true;
            }
        }
        return false;
    }
};