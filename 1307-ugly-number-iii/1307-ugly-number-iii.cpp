class Solution {
public:
    int nthUglyNumber(int n, int x, int y, int z) {
        int l=1, h=2*(int) 1e9;
        long a = long(x), b=long(y), c=long(z);
        long ab=a*b/ __gcd(a,b);
        long bc=b*c/ __gcd(b,c);
        long ac=a*c/ __gcd(a,c);
        long abc=a*bc/ __gcd(a,bc);
        while(l<h)
        {
            int m= l+(h-l)/2;
            int cnt= m/a + m/b +m/c - m/ab -m/bc -m/ac +m/abc;
            if(cnt<n) l=m+1;
            else h=m;
        }
        return l;
    }
};