class Solution {
public:
int m=1e9+7;
    int countHomogenous(string s) {
        int n=s.length();
        int res=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i>0&&s[i]==s[i-1]) cnt++;
            else cnt=1;
            res=(res+cnt)%m;
        }
        return res;
    }
};