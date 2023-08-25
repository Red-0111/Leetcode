class Solution {
public:

//------------------------ RECURSION -----------------------------------

    // bool isit(string s1, int i, string s2, int j, string res, string s3)
    // {
    //     bool ans=false;
    //     if(res==s3&&s1.length()==i&&s2.length()==j) return true;
    //     if(i<s1.length()) ans|=isit(s1,i+1,s2,j,res+s1[i],s3);
    //     if(j<s2.length()) ans|=isit(s1,i,s2,j+1,res+s2[j],s3);
    //     return ans;
    // }

    // bool isInterleave(string s1, string s2, string s3) {
    //     if(s1.length()+s2.length()!=s3.length()) return false;
    //     return isit(s1,0,s2,0,"",s3);
    // }

//--------------------DYNAMIC PROGRAMMING-------------------------------

    bool init(string s1, int i, string s2, int j, vector<vector<int>>&dp,string s3)
    {
        if(i+j==s3.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=0;
        if(i<s1.size()&&s1[i]==s3[i+j]) ans|= init(s1,i+1,s2,j,dp,s3);
        if(j<s2.size()&&s2[j]==s3[i+j]) ans|= init(s1,i,s2,j+1,dp,s3);
        return dp[i][j]=ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return init(s1,0,s2,0,dp,s3);
    }
};