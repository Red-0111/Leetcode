class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>> gp;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<gs.size();i++)
        {
            int k=gs[i];//desired size
            mp[k].push_back(i);
            if(mp[k].size()==k)
            {
                gp.emplace_back(move(mp[k]));
                mp[k].clear();
            }
        }
        return gp;
    }
};