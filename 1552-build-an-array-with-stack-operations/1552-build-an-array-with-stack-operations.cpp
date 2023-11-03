class Solution {
public:
    vector<string> buildArray(vector<int>& tar, int n) {
        vector<string> v;
        int val=1, i=0, maxi=tar[tar.size()-1];
        while(val<=maxi)
        {
            v.push_back("Push");
            if(tar[i]==val) i++;
            else v.push_back("Pop");
            val++;
        }
        return v;
    }
};