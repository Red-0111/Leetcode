class Solution {
public:

    vector<int> ans;
    vector<int> ds;

    void gensubs(vector<int>&nums,int idx)
    {
        if(idx==nums.size())
        {
            int xa=0;
            for(auto &i:ds) xa^=i;
            ans.push_back(xa);
            return;
        }
        ds.push_back(nums[idx]);
        gensubs(nums,idx+1);
        ds.pop_back();
        gensubs(nums,idx+1);
    }

    int subsetXORSum(vector<int>& nums) {
        gensubs(nums,0);
        return accumulate(ans.begin(),ans.end(),0);
    }
};