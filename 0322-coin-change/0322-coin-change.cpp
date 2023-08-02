class Solution {
public:    
    int dp[10001];

    int f(int amt, vector<int>& c)
    {
        if(amt==0) return 0;
        if(dp[amt]!=-1) return dp[amt];
        int ans=1e9;
        for(auto i:c) if(amt>=i) ans=min(ans,f(amt-i,c)+1);
        dp[amt]=ans;
        return ans;
    }
    
    int coinChange(vector<int>& c, int amt) {
        memset(dp,-1,sizeof(dp));
        int ans=f(amt,c);
        if(ans>=1e9) ans=-1;
        return ans;
    }
};