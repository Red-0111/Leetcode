class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& p) {
        vector<int> s,e;
        for(auto &t:f) s.push_back(t[0]), e.push_back(t[1]);
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        vector<int> res;
        for(int t:p)
        {
            int sd=upper_bound(s.begin(),s.end(),t)-s.begin();
            int ed=lower_bound(e.begin(),e.end(),t)-e.begin();
            res.push_back(sd-ed);
        }
        return res;
    }
};