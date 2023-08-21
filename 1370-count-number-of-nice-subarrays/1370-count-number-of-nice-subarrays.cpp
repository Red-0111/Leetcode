class Solution {
public:

    int x(vector<int>&a, int k)
    {
        int res=0,i=0,n=a.size();
        for(int j=0;j<n;j++)
        {
            k-=a[j]%2;
            while(k<0) k+=a[i++]%2;
            res+=j-i+1;
        }
        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return x(nums,k)-x(nums,k-1);
    }
};