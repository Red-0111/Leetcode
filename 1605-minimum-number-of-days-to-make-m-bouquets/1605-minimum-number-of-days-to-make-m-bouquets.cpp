class Solution {
public:

    bool f(vector<int>& bd, int m, int k, int day)
    {
        int tot=0;
        for(int i=0;i<bd.size();i++)
        {
            int cnt=0;
            while(i<bd.size()&&cnt<k&&bd[i]<=day)
            {
                cnt++;
                i++;
            }

            if(cnt==k)
            {
                tot++;
                i--;
            }

            if(tot>=m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bd, int m, int k) {
        if((long long)m*k>bd.size()) return -1;
        int l=1, h=1e9;
        while(l<h)
        {
            int mid=l+(h-l)/2;
            if(f(bd,m,k,mid)) h=mid;
            else l=mid+1;
        }
        return l;
    }
};