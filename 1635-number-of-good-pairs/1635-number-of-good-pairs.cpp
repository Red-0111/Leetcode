class Solution {
public:
    int numIdenticalPairs(vector<int>& n) {
        return accumulate(n.begin(),n.end(),0,[cnt=unordered_map<int,int>{}](auto x,auto y)mutable{
            return x+cnt[y]++;
        });
    }
};