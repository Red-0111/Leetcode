class Dj{
    vector<int> p,s;
    public:
    Dj(int n)
    {
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0;i<n;i++)
        {
            p[i]=i;
            s[i]=1;
        }
    }
    int fupar(int n)
    {
        if(n==p[n]) return n;
        return p[n]=fupar(p[n]);
    }
    void ubys(int u, int v)
    {
        int ulpu=fupar(u);
        int ulpv=fupar(v);
        if(ulpu<ulpv)
        {
            p[ulpu]=ulpv;
            s[ulpu]+=s[ulpv];
        }
        else
        {
            p[ulpv]=ulpu;
            s[ulpv]=s[ulpu];
        }
    }
};


class Solution {
    int kru(int n,vector<vector<int>>& ed,int sk,int pr=-1)
    {
        Dj ds(n);
        int ms=0;
        if(pr!=-1)
        {
            ms+=ed[pr][2];
            ds.ubys(ed[pr][0],ed[pr][1]);
        }
        for(int i=0;i<ed.size();i++)
        {
            if(i==sk) continue;
            int u=ed[i][0];
            int v=ed[i][1];
            int wt=ed[i][2];
            if(ds.fupar(u)==ds.fupar(v)) continue;
            ds.ubys(u,v);
            ms+=wt;
        }
        for(int i=0;i<n;i++)
        {
            if(ds.fupar(i)!=ds.fupar(0)) return INT_MAX;
        }
        return ms;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& ed) {
        for(int i=0;i<ed.size();i++) ed[i].push_back(i);
        sort(ed.begin(),ed.end(), [](const vector<int>& a, const vector<int>& b){
            return a[2]<b[2];
        });
        int omst=kru(n,ed,-1);
        vector<int> cr,noncr;
        for(int i=0;i<ed.size();i++)
        {
            if(omst<kru(n,ed,i))
            {
                cr.push_back(ed[i][3]);
            }
            else if(omst==kru(n,ed,-1,i))
            {
                noncr.push_back(ed[i][3]);
            }
        }
        return {cr,noncr};
    }
};