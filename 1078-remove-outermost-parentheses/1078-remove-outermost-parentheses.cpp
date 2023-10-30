class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int op=0;
        for(char c:s)
        {
            if(c=='('&& op++>0) res+=c;
            if(c==')'&& op-->1) res+=c;
        }
        return res;
    }
};