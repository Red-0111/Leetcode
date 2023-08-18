class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n,0);
        set<pair<int,int>> rs;
        for(auto &r:roads)
        {
            deg[r[0]]++;
            deg[r[1]]++;
            rs.insert({r[1],r[0]});
            rs.insert({r[0],r[1]});
        }
        int mr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rnk=deg[i]+deg[j];
                if(rs.find({i,j})!=rs.end()) rnk--;
                mr=max(mr,rnk);
            }
        }
        return mr;
    }
};