class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long mis=1;
        int res=0;
        size_t i=0;
        while(mis<=n)
        {
            if(i<nums.size()&&nums[i]<=mis)
            {
                mis+=nums[i];
                i++;
            }
            else{
                mis+=mis;
                res++;
            }
        }
        return res;
    }
};