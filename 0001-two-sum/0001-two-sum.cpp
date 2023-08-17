class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
       unordered_map<int,int> vis;
       for(int i=0;i<nums.size();i++)
       {
           int n=nums[i];
           int com=tar-n;
           if(vis.count(com)) return {vis[com],i};
           vis[n]=i;
       }
       return {};
    }
};