class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, cnt=0, n=s.size()-1;
        unordered_map<char,int> mp;
        for(r=0;r<=n;r++)
        {
            mp[s[r]]++;
            while(mp['a']&&mp['b']&&mp['c'])
            {
                cnt+=1+(n-r);
                mp[s[l]]--;
                l++;
                cout<<r<<" ";
            }
        }
        return cnt;
    }
};