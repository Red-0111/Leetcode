// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int s=0;
        long long int e=n;
        long long int mb;
        while(s<=e)
        {
            long long int m=(s+e)/2;
            if(isBadVersion(m)==1)
            {
                mb=m;
                e=m-1;
            }
            else s=m+1;
        }
        return mb;
    }
};