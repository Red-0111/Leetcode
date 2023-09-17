class Solution {
public:

    void f(vector<string>& ans, const string& num, const int& tar, string exp, int x, int prevnum, long long curt)
    {
        int n=num.size();
        if(x==n)
        {
            if(curt==tar) ans.push_back(exp);
        }
        string curstr="";
        long long curnum=0;
        for(int i=x;i<n;i++)
        {
            if(i>x&&num[x]=='0') break;
            curstr+=num[i];
            curnum=curnum*10+(num[i]-'0');
            if(x==0) f(ans,num, tar, exp+curstr,i+1,curnum,curt+curnum);
            else
            {
                f(ans,num,tar,exp+"+"+curstr,i+1,curnum,curt+curnum);
                f(ans,num,tar,exp+"-"+curstr,i+1,-curnum,curt-curnum);
                f(ans,num,tar,exp+"*"+curstr,i+1,prevnum*curnum,curt-prevnum+(prevnum*curnum));
            }
        }
    }

    vector<string> addOperators(string num, int tar) {
        vector<string> ans;
        f(ans,num,tar,"",0,0,0);
        return ans;
    }
    
    
    
};

