class Solution {
public:
    int n;
    bool check()
    {
        if(n>0&&n%4==0)
        {
            n/=4;
            return check();
        }
        else return n==1;
    }


    bool isPowerOfFour(int x) {
        n=x;
        return check();
    }
};