class Solution {
public:
    double champagneTower(int p, int qr, int qg) {
        vector<double> cr(1,p);
        for(int i=0;i<=qr;i++)
        {
            vector<double> nr(i+2,0);
            for(int j=0;j<=i;j++)
            {
                if(cr[j]>=1)
                {
                    nr[j]+=(cr[j]-1)/2.0;
                    nr[j+1]+=(cr[j]-1)/2.0;
                    cr[j]=1;
                }
            }
            if(i!=qr) cr=nr;
        }
        return cr[qg];
    }
};