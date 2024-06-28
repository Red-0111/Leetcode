class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n,0);
        for(auto &r:roads)
        {
            int u=r[0];
            int v=r[1];
            deg[u]++;
            deg[v]++;
        }
        sort(deg.begin(),deg.end());
        long long res=0;
        for(long long i=1;i<=n;i++) res+=deg[i-1]*i;
        return res;
    }
};