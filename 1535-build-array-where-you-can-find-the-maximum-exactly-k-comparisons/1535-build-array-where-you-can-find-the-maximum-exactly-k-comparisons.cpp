class Solution {
public:
long long w[51][101][51];
const int mod=1e9+7;
    int numOfArrays(int n, int m, int k) {
        for(int j=1;j<=m;j++) w[1][j][1]=1;
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=m;b++)
            {
                for(int c=1;c<=k;c++)
                {
                    long long s=0;
                    s=(s+b*w[a-1][b][c])%mod;
                    for(int x=1;x<b;x++) s=(s+w[a-1][x][c-1])%mod;
                    w[a][b][c]=(w[a][b][c]+s)%mod;
                }
            }
        }
        long long ans=0;
        for(int j=1;j<=m;j++) ans=(ans+w[n][j][k])%mod;
        return int(ans);
    }
};