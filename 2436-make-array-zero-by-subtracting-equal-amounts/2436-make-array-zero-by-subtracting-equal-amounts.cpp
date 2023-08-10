class Solution {
public:
    int minimumOperations(vector<int>& n) {
        unordered_set<int> s(n.begin(),n.end());
        return s.size()-s.count(0);
    }
};