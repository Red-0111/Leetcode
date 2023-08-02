class Solution {
public:
    int countGoodStrings(int l, int h, int z, int o) {
        vector<int> dp(h+1);
        dp[0]=1;
        int m=1e9+7;
        for(int i=min(o,z);i<=h;i++)
        {
            if(i>=z) dp[i]=(dp[i]+dp[i-z])%m;
            if(i>=o) dp[i]=(dp[i]+dp[i-o])%m;
        }
        int s=0;
        for(int i=l;i<=h;i++) s=(s+dp[i])%m;
        return s;  
    }
};