class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int maxc=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                i=j+1;
            }
            maxc=max(maxc,j-i+1);
            j++;
        }
        return maxc;
    }
};