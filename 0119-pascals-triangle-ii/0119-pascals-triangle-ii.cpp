class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> dp(n+1,1);
        for(int r=2;r<=n;r++)
        {
            for(int c=r-1;c>0;c--)
            {
                dp[c]+=dp[c-1];
            }
        }
        return dp;
    }
};