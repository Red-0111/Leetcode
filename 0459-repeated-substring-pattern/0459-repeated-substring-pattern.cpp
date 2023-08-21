class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string dbl=s+s;
        string sub=dbl.substr(1,dbl.size()-2);
        return sub.find(s)!=string::npos;
    }
};