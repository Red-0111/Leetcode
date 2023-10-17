class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        unordered_set<int> rs;
        for(int &i:lc) rs.insert(i);
        for(int &j:rc) rs.insert(j);
        int cnt=0;
        int r=-1;
        for(int i=0;i<n;i++)
        {
            if(rs.find(i)==rs.end())
            {
                cnt++;
                r=i;
                if(cnt>1) return false;
            }
        }
        if(r==-1) return false;
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(r);
        vis[r]=true;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
                if(lc[i]!=-1)
                {
                    if(vis[lc[i]]) return false;
                    vis[lc[i]]=true;
                    q.push(lc[i]);
                }
                if(rc[i]!=-1)
                {
                    if(vis[rc[i]]) return false;
                    vis[rc[i]]=true;
                    q.push(rc[i]);
                }
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
};