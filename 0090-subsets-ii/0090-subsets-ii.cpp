class Solution {
public:

    void f(vector<int>&nums, vector<int>& cur, vector<vector<int>>& ans, int x)
    {

        ans.push_back(cur);
        for(int i=x;i<nums.size();i++)
        {
            if(i>x&&(nums[i]==nums[i-1]))
            {
                continue;
                return;
            }
            cur.push_back(nums[i]);
            f(nums,cur,ans,i+1);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        f(nums,cur,ans,0);
        return ans;
    }
};