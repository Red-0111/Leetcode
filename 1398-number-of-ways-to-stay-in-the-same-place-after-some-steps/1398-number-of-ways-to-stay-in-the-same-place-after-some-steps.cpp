class Solution {
public:

    long long dp(int s, int i,int a, const int mod, vector<vector<long long>>&mem)
    {
        if(s==0) return (i==0)?1:0;
        if(s<0||i<0||i>=a) return 0;
        if(mem[s][i]!=-1) return mem[s][i];
        long long w=dp(s-1,i,a,mod,mem)%mod;
        w+=dp(s-1,i-1,a,mod,mem)%mod;
        w+=dp(s-1,i+1,a,mod,mem)%mod;
        mem[s][i]=w%mod;
        return w%mod;
    }

    int numWays(int steps, int arrLen) {
        const int mod=1000000007;
        vector<vector<long long>> mem(steps+1,vector<long long>(min(arrLen,steps)+1,-1));
        return dp(steps,0,arrLen,mod,mem);
    }
};