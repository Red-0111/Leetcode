const int M = 1e9 + 7;
vector<int> p={2,3,5,7,11,13,17,19,23,29};

class Solution {  
public:  

    int Madd(int a, int b)
    {
        a+=b;
        if(a>=M) a-=M;
        return a;
    }


    int squareFreeSubsets(vector<int>& v) {  
        int n=v.size();
        vector<vector<int>> f(n,vector<int>(10));
        for(int i=0;i<n;i++)
        {
            int x=v[i];
            for(int j=0;j<10;j++)
            {
                while(x%p[j]==0)
                {
                    x/=p[j];
                    f[i][j]++;
                }
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(1<<10));
        for(int i=0;i<n;i++)
        {
            dp[i+1]=dp[i];
            bool ok=true;
            int mask=0;
            for(int j=0;j<10;j++)
            {
                if(f[i][j]>1)
                {
                    ok=false;
                    break;
                }
                if(f[i][j]==1) mask |=(1<<j);
            }

            if(ok)
            {
                for(int j=0;j<(1<<10);j++)
                {
                    if((j&mask)==0) dp[i+1][j|mask]=Madd(dp[i+1][j|mask],dp[i][j]);
                }
                dp[i+1][mask]=Madd(dp[i+1][mask],1);
            }
        }
        int ans=0;
        for(int i=0;i<(1<<10);i++) ans=Madd(ans,dp[n][i]);
        return ans; 
    }  
};