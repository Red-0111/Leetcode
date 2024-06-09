class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int s=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            int t=s%k;
            t=(t+k)%k;
            cnt+=mp[t];
            mp[t]++;
        }
        return cnt;
    }
};