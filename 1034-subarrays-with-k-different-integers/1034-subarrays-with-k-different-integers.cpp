class Solution {
public:

    int x(vector<int>& a,int k)
    {
        int i=0,res=0;
        unordered_map<int,int> m;
        for(int j=0;j<a.size();j++)
        {
            if(!m[a[j]]++) k--;
            while(k<0)
            {
                if(!--m[a[i]]) k++;
                i++;
            }
            res+=j-i+1;
        }
        return res;
    }


    int subarraysWithKDistinct(vector<int>& a, int k) {
        return x(a,k)-x(a,k-1);
    }
};