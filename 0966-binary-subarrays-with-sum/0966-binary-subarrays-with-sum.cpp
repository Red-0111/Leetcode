class Solution {
public:

    int h(vector<int>& nums,int goal)
    {
        int n=nums.size(),i=0,j=0,cnt=0,s=0;
        while(j<n)
        {
            s+=nums[j];
            while(i<=j&&s>goal) s-=nums[i++];
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return h(nums,goal)-h(nums,goal-1);
    }
};