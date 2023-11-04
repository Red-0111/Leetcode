class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int m=0;
        for(auto i:left) m=max(i,m);
        for(auto i:right) m=max(n-i,m);
        return m;
    }
};