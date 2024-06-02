class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        set<int> prev;
        int minv=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            set<int>next;
            for(int v:prev) next.insert(v&nums[i]);
            next.insert(nums[i]);
            for(int v:next) minv=min(minv,abs(k-v));
            prev=next;
        }
        return minv;
    }
};