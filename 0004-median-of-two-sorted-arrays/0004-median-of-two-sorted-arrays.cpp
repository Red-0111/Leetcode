class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1);
        int l=0, r=m;
        int tot=m+n+1;
        while(l<=r)
        {
            int f=l+(r-l)/2;
            int s=tot/2-f;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(f>0) l1=nums1[f-1];
            if(s>0) l2=nums2[s-1];
            if((f>=0)&&(f<m)) r1= nums1[f];
            if((s>=0)&&(s<n)) r2= nums2[s];
            if(l1<=r2&&l2<=r1)
            {
                if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                else return max(l1,l2);
            }
            else if(l1>l2) r=f-1;
            else l=f+1;
        }
        return 0;
    }
};