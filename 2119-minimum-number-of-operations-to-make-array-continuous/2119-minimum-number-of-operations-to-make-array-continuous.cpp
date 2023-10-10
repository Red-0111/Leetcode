class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n=nums.size();
        int ans=n;
        unordered_set<int> mp;
        for(int x:nums) mp.insert(x);
        vector<int> uni(mp.begin(),mp.end());
        sort(uni.begin(),uni.end());
        int j=0;
        int m=uni.size();
        for(int i=0;i<m;i++)
        {
            while(j<m&&uni[j]<uni[i]+n) j++;
            ans=min(ans,n-j+i);
        }
        return ans;
    }
};