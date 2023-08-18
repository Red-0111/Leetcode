class Solution {
public:

    int p=0;
    void dfs(vector<vector<int>>&g,int i, int j)
    {
        if(i<0||j<0||i>g.size()-1||j>g[0].size()-1||g[i][j]==0)
        {
            p++;
            return;
        }
        if(g[i][j]==-1) return;
        g[i][j]=-1;
        dfs(g,i+1,j);
        dfs(g,i-1,j);
        dfs(g,i,j+1);
        dfs(g,i,j-1);
    }

    int islandPerimeter(vector<vector<int>>& g) {
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                if(g[i][j]) dfs(g,i,j);
            }
        }
        return p;
    }
};