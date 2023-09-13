class Solution {
public:
    int candy(vector<int>& rs) {
        int n=rs.size();
        vector<int> cs(n,1);
        for(int i=1;i<n;i++)
        {
            if(rs[i-1]<rs[i]&&cs[i-1]>=cs[i]) cs[i]=cs[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(rs[i+1]<rs[i]&&cs[i+1]>=cs[i]) cs[i]=cs[i+1]+1;
        }

        int tc=0;

        for(int i=0;i<n;i++) tc+=cs[i];
        return tc;
    }
};