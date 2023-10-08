class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(),r=0;
        for(int i=0;i<n;i++)
        {
            if(i>r) return 0;
            r=max(r,nums[i]+i);
        }
        return 1;
    }
};