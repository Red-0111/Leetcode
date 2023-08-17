class Solution {
public:

    vector<int> DIR={0,1,0,-1,0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0) q.emplace(i,j);
                else mat[i][j]=-1;
            }
        }
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int x=0;x<4;x++)
            {
                int ni=i+DIR[x], nj=j+DIR[x+1];
                if(ni<0||ni==m||nj<0||nj==n||mat[ni][nj]!=-1) continue;
                mat[ni][nj]=mat[i][j]+1;
                q.emplace(ni,nj);
            }
        }
        return mat;
    }
};