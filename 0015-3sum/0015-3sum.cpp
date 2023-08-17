class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int tar=0;
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<vector<int>> out;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==tar)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<tar) j++;
                else k--;
            }
        }
        for(auto t:s) out.push_back(t);
        return out;
    }
};