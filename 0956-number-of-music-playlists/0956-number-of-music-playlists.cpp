class Solution {
public:
    #define ll long long
    const int m=1e9+7;

    ll f(int n, int goal, int k, vector<vector<int>>& dp)
    {
        if(n==0&&goal==0) return 1;
        if(n==0||goal==0) return 0;
        if(dp[n][goal]!=-1) return dp[n][goal];
        ll pick=f(n-1,goal-1,k,dp)*n;
        ll nopick=f(n,goal-1,k,dp)*max(n-k,0);
        return dp[n][goal]=(pick+nopick)%m;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n+1,vector<int>(goal+1,-1));
        return f(n,goal,k,dp);
    }
};