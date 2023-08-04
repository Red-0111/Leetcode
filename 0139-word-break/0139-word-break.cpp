class Solution {
public:

    bool f(string s, unordered_set<string>& st, vector<int>& dp, int start )
    {
        if(start==s.size()) return true;
        if(dp[start]!=-1) return dp[start];
        for(int i=start;i<s.size();i++)
        {
            if(st.count(s.substr(start,i+1-start))&&f(s,st,dp,i+1))
            {
                dp[start]=true;
                return true;
            }
        }
        return dp[start]=false;
    }

    bool wordBreak(string s, vector<string>& wd) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> st(wd.begin(),wd.end());
        return f(s,st,dp,0);
    }
};