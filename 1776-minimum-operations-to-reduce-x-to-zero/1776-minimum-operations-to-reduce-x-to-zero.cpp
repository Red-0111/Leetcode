class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        for(int n:nums) tot+=n;
        int maxl=-1, cursum=0;
        for(int l=0,r=0;r<nums.size();r++)
        {
            cursum+=nums[r];
            while(l<=r&&cursum>tot-x) cursum-=nums[l++];
            if(cursum==tot-x) maxl=max(maxl,r-l+1);
        }
        return maxl==-1?-1:nums.size()-maxl;
    }
};