class Solution {
    int f[100005][2];
public:
    int minimumOperations(vector<int>& nums) {
        memset(f,0,sizeof(f));
        int n=nums.size(), i , j, k, ans=0;
        for(int i=0;i<n;i++)
        {
            f[nums[i]][i&1]++;
        }
        for(int i=1,j=k=0;i<=100000;i++)
        {
            ans=max({ans,f[i][0]+k,f[i][1]+j});
            j=max(j,f[i][0]);
            k=max(k,f[i][1]);
        }
        return n-ans;
    }
};