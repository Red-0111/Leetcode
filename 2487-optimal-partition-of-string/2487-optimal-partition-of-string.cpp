class Solution {
public:
    int partitionString(string s) {
        int ind=0;
        int cnt=0;
        unordered_map<char, bool> m;
        while(ind<=s.length())
        {
            if(m.find(s[ind])!=m.end())
            {
                cnt++;
                m.clear();
            }
            m[s[ind]]=true;
            ind++;
        }
        return cnt+1;
    }
};