class Solution {
public:
    int lengthOfLastWord(string s) {
        int si=s.size(),c=0,f=0;
        for(int i=si-1;i>=0;i--)
        {
            if(s[i]==' '&&f) break;
            if(s[i]!=' ')
            {
                f=1;
                c++;
            }
        }
        return c;
    }
};