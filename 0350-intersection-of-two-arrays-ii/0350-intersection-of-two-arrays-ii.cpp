class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> f;
        vector<int> ans;
        for(int i:nums1) f[i]++;
        for(int i:nums2)
        {
            if(f[i]>0)
            {
                ans.push_back(i);
                f[i]--;
            }
        }
        return ans;
    }
};