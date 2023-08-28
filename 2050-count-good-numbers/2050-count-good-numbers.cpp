class Solution {
public:

    int p=1e9+7;

    long long pou(long long x, long long y)
    {
        long long res=1;
        x=x%p;
        if(x==0) return 0;
        while(y>0)
        {
            if(y&1) res=(x*res)%p;
            y=y/2;
            x=(x*x)%p;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long c4s=n/2;
        long long c5s=n-c4s;
        long long ans=(((pou(4LL,c4s)%p)*(pou(5LL,c5s)%p))%p);
        return (int)ans;
    }
};