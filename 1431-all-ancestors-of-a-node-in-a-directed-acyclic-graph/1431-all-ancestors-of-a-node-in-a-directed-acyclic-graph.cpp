class Solution {
    void dfs(vector<vector<int>>& gr, int p, int cur, vector<vector<int>>& res, vector<bool> &vis)
    {
        vis[cur]=true;
        for(int dest:gr[cur])
        {
            if(!vis[dest])
            {
                res[dest].push_back(p);
                dfs(gr,p,dest,res,vis);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> gr(n);
        for(const auto&e: edges) gr[e[0]].push_back(e[1]);
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            dfs(gr,i,i,res,vis);
        }
        for(int i=0;i<n;i++) sort(res[i].begin(),res[i].end());
        return res;
    }
};