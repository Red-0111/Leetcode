class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rels, vector<int>& t) {
        vector<vector<int>> g(n);
        for(const vector<int>&r:rels)
        {
            int p=r[0]-1;
            int n=r[1]-1;
            g[p].push_back(n);
        }
        vector<int> dp(n,-1);
        function<int(int)> calc=[&](int c)
        {
            if(dp[c]!=-1) return dp[c];
            if(g[c].empty())
            {
                dp[c]=t[c];
                return dp[c];
            }
            int maxpre=0;
            for(int p:g[c]) maxpre=max(maxpre,calc(p));
            dp[c]=maxpre+t[c];
            return dp[c];
        };
        int mint=0;
        for(int c=0;c<n;c++) mint=max(mint,calc(c));
        return mint;
    }
};