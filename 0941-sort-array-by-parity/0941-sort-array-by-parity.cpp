class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& n) {
        vector<int> e,o;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]%2==0) e.push_back(n[i]);
            else o.push_back(n[i]);
        }
        for(int num:o) e.push_back(num);
        return e;
    }
};