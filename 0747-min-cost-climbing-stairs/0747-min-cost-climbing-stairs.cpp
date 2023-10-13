class Solution {
public:
    int minCostClimbingStairs(vector<int>& c) {
        int n=c.size();
        for(int i=2;i<n;i++) c[i]+=min(c[i-1],c[i-2]);
        return min(c[n-1],c[n-2]);
    }
};