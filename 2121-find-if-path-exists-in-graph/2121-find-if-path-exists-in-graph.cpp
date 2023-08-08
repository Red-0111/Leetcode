class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        unordered_map<int,vector<int>> m;
        unordered_map<int,bool> vis;
        for(auto it:e)
        {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
            vis[it[0]]=false;
            vis[it[1]]=false;
        }
        queue<int> q;
        q.push(s);
        vis[s]=true;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            vector<int> vec=m[temp];
            for(int i=0;i<vec.size();i++)
            {
                if(vis[vec[i]]==true) continue;
                else
                {
                    q.push(vec[i]);
                    vis[vec[i]]=true;
                }
            }
        }
        return vis[d];
    }
};