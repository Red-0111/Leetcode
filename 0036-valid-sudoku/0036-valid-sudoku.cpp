class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++)
        {
            unordered_set<char> checkr;
            for(int c=0;c<9;c++)
            {
                if(board[r][c]!='.'&&checkr.find(board[r][c])!=checkr.end()) return false;
                checkr.insert(board[r][c]);
            }
        }

        for(int c=0;c<9;c++)
        {
            unordered_set<char> checkc;
            for(int r=0;r<9;r++)
            {
                if(board[r][c]!='.'&&checkc.find(board[r][c])!=checkc.end()) return false;
                checkc.insert(board[r][c]);
            }
        }

        vector<unordered_set<char>> checks(9);
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                int loc=(r/3)*3+c/3;
                if(board[r][c]!='.'&&checks[loc].find(board[r][c])!=checks[loc].end()) return false;
                checks[loc].insert(board[r][c]);
            }
        }
        return true;
    }
};