class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        int m=s.length(),n=t.length();
        while(i<m&&j<n)
        {
            if(s[i]==t[j]) j++;
            i++;
        }
        return n-j;
    }
};