class Solution {
public:
    int change(int amnt, vector<int>& cns) {
        int n=cns.size();
        vector<vector<int>> dp(n,vector<int>(amnt+1,0));
        for(int j=0;j<=amnt;j++) dp[0][j]= (j%cns[0]==0);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amnt;j++)
            {
                long notake=dp[i-1][j];
                long take=0;
                if(cns[i]<=j) take=dp[i][j-cns[i]];
                dp[i][j]=take+notake;
            }
        }
        return dp[n-1][amnt];
    }
};