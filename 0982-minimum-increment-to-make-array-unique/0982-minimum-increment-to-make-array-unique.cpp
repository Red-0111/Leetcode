class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int mini=0;
        for(int i:nums)
        {
            cnt=max(cnt,i);
            mini+=cnt-i;
            cnt++;
        }
        return mini;
    }
};