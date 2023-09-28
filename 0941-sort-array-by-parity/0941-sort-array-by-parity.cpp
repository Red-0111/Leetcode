class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& n) {
        int l=0, r=n.size()-1;
        while(l<r)
        {
            if(n[l]%2==0) l++;
            else
            {
                swap(n[l],n[r]);
                r--;
            }
        }
        return n;
    }
};