class Solution {
public:

    int nc(string s,int cur)
    {
        while(cur>-1&&s[cur]=='#')
        {
            int cnt=1;
            cur--;
            while(cur>-1&&cnt>0)
            {
                if(s[cur]=='#') cnt++;
                else cnt--;
                cur--;
            }
        }
        return cur;
    }

    bool backspaceCompare(string s, string t) {
        int i=nc(s,s.length()-1);
        int j=nc(t,t.length()-1);
        while(i>-1&&j>-1)
        {
            if(s[i]!=t[j]) return false;
            i=nc(s,i-1);
            j=nc(t,j-1);
        }
        return i==-1 && j==-1;
    }
};