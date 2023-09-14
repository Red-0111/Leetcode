class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tts) {
        unordered_map<string, vector<string>> g;
        for(auto& t: tts) g[t[0]].push_back(t[1]);
        for(auto& [_, des]:g) sort(des.rbegin(),des.rend());
        vector<string> it;
        function<void(const string&)> dfs=[&](const string& air)
        {
            while(!g[air].empty())
            {
                string nxt=g[air].back();
                g[air].pop_back();
                dfs(nxt);
            }
            it.push_back(air);
        };
        dfs("JFK");
        reverse(it.begin(),it.end());
        return it;
    }
};