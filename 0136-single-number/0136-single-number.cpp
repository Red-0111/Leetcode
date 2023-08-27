class Solution {
public:
    int singleNumber(vector<int>& n) {
        int x=0;
        for(int i=0;i<n.size();i++) x=x^n[i];
        return x;
    }
};