class Solution {
public:

    bool canform(const vector<int> nums, int m, int p)
    {
        int cnt=0;
        for(int i=0;i<nums.size()-1&&cnt<p;)
        {
            if(nums[i+1]-nums[i]<=m)
            {
                cnt++;
                i+=2;
            }
            else i++;
        }
        return cnt>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0, r=nums.back()-nums.front();

        while(l<r)
        {
            int m=(l+r)/2;
            if(canform(nums,m,p)) r=m;
            else l=m+1;
        }
        return l;
    }
};