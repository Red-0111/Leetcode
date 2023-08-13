class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int ind=0;ind<n;ind++)
        {
            int i=ind+1;
            bool twoid=false;
            bool threeid=false;
            bool consec=false;

            if(ind>0&&nums[ind]==nums[ind-1]) twoid=dp[i-2];
            if(ind>1&&nums[ind]==nums[ind-1]&&nums[ind-1]==nums[ind-2]&&nums[ind]==nums[ind-2]) threeid=dp[i-3];
            if(ind>1&&nums[ind]==nums[ind-1]+1&&nums[ind-1]==nums[ind-2]+1) consec=dp[i-3];
            dp[i]=twoid||threeid||consec;
        }
        return dp[n];
    }
};