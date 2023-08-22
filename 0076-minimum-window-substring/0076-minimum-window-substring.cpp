class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need, win;
        int l=0, r=0, v=0, st=0, len=INT_MAX;
        for(char c:t) need[c]++;
        while(r<s.size())
        {
            char c=s[r];
            r++;
            if(need.count(c))
            {
                win[c]++;
                if(need[c]==win[c]) v++;
            }

            while(need.size()==v)
            {if(r-l<len)
            {
                st=l;
                len=r-l;
            }

            char d=s[l];
            l++;
            if(need.count(d))
            {
                if(win[d]==need[d]) v--;
                win[d]--;
            }}
            
        }
        return len==INT_MAX?"":s.substr(st,len);
    }
};