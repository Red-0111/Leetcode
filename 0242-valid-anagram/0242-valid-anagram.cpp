class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cs(256,0);
        vector<int> ct(256,0);
        for(int i=0;i<s.size();i++) cs[s[i]]++;
        for(int i=0;i<t.size();i++) ct[t[i]]++;
        return cs==ct;
    }
};