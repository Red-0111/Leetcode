class Solution {
public:

    int fp(vector<int>& p, int n)
    {
        if(p[n]==n) return n;
        return p[n]=fp(p,p[n]);
    }

    int minCostConnectPoints(vector<vector<int>>& pt) {
        int n=pt.size();
        vector<pair<int,pair<int,int>>> ed;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d=abs(pt[i][0]-pt[j][0])+abs(pt[i][1]-pt[j][1]);
                ed.push_back({d,{i,j}});
            }
        }
        sort(ed.begin(),ed.end());
        vector<int>p(n);
        for(int i=0;i<n;i++) p[i]=i;
        int mc=0,ne=0;
        for(auto e:ed)
        {
            int dis=e.first;
            int u=e.second.first;
            int v=e.second.second;
            int pu=fp(p,u);
            int pv=fp(p,v);
            if(pu!=pv)
            {
                p[pu]=pv;
                mc+=dis;
                ne++;
            }
            if(ne==n-1) break;
        }
        return mc;
    }
};