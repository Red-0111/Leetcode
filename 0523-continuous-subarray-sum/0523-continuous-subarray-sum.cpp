class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(mp.find(s%k)!=mp.end())
            {
                if(i-mp[s%k]>=2) return true;
            }
            else mp[s%k]=i;
        }
        return false;
    }
};