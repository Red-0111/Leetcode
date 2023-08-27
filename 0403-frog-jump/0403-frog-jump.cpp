class Solution {
public:

    bool f(int i, int k, vector<int>& s, vector<vector<int>>& dp)
    {
        bool a= false;
        if(i==s.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        for(int j=i+1;j<s.size();j++)
        {
            if(s[j]>s[i]+k+1) break;
            else if(s[j]==s[i]+k-1) a|=f(j,k-1,s,dp);
            else if(s[j]==s[i]+k) a|=f(j,k,s,dp);
            else if(s[j]==s[i]+k+1) a|=f(j,k+1,s,dp);
        }
        return dp[i][k]=a;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size()+2,vector<int>(4000,-1));
        return f(0,0,stones,dp);
    }
};