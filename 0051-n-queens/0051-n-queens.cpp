class Solution {
public:

    void x(vector<vector<string>>& ans, vector<string>&s, int c, vector<int>& lr,vector<int>& ld,vector<int>& ud, int n)
    {
        if(c==n)
        {
            ans.push_back(s);
            return;
        }
        for(int r=0;r<n;r++)
        {
            if(lr[r]==0&&ld[r+c]==0&&ud[n-1+c-r]==0)
            {
                s[r][c]='Q';
                lr[r]=1;
                ld[r+c]=1;
                ud[n-1+c-r]=1;
                x(ans,s,c+1,lr,ld,ud,n);
                s[r][c]='.';
                lr[r]=0;
                ld[r+c]=0;
                ud[n-1+c-r]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> s(n);
       string b(n,'.');
       for(int i=0;i<n;i++) s[i]=b;
       vector<int> lr(n,0), ld(2*n-1,0), ud(2*n-1,0);
       x(ans, s, 0, lr, ld, ud,n);
       return ans;
    }
};