class Solution {
public:

    void x(vector<int>nums,int i, vector<int> out, vector<vector<int>> &ans )
    {
        if(i>=nums.size())
        {
            ans.push_back(out);
            return;
        }
        x(nums,i+1,out,ans);
        int el=nums[i];
        out.push_back(nums[i]);
        x(nums,i+1,out,ans);
        return;
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> ans;       
        int i=0;
        x(nums,i,out,ans);
        return ans; 
    }
};