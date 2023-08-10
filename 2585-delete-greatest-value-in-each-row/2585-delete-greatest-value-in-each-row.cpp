class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& g) {
        unordered_map<int, priority_queue<int>> mp;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[0].size();j++)
            {
                mp[i].push(g[i][j]);
            }
        }
        int s=0;
        for(int i=0;i<g[0].size();i++)
        {
            int maxv=-1;
            for(int j=0;j<g.size();j++)
            {
                int tmp=mp[j].top();
                mp[j].pop();
                maxv=max(maxv,tmp);
            }
            s+=maxv;
        }
        return s;
    }
};