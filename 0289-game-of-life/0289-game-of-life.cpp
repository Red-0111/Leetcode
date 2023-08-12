class Solution {
public:

    int getln(vector<vector<int>>& cur, int i, int j, int m, int n)
    {
        int ln=0;
        if(i>0) if(cur[i-1][j]==1||cur[i-1][j]==3) ln++;
        if(i<m-1) if(cur[i+1][j]==1||cur[i+1][j]==3) ln++;
        if(j>0) if(cur[i][j-1]==1||cur[i][j-1]==3) ln++;
        if(j<n-1) if(cur[i][j+1]==1||cur[i][j+1]==3) ln++;

        if(i>0&&j>0) if(cur[i-1][j-1]==1||cur[i-1][j-1]==3) ln++;
        if(i>0&&j<n-1) if(cur[i-1][j+1]==1||cur[i-1][j+1]==3) ln++;
        if(i<m-1&&j>0) if(cur[i+1][j-1]==1||cur[i+1][j-1]==3) ln++;
        if(i<m-1&&j<n-1) if(cur[i+1][j+1]==1||cur[i+1][j+1]==3) ln++;
        return ln;
    }

    void gameOfLife(vector<vector<int>>& bo) {
        int m=bo.size();
        int n=bo[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ln=getln(bo,i,j,m,n);
                if(bo[i][j]==0)
                {
                    if(ln==3) bo[i][j]=2;
                }
                else if(bo[i][j]==1)
                {
                    if(ln<2||ln>3) bo[i][j]=3;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(bo[i][j]==2) bo[i][j]=1;
                else if(bo[i][j]==3) bo[i][j]=0;
            }
        }
    }
};