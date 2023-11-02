class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto p:mp) pq.push({p.second, p.first});
        string res="";
        pair<int,char>tmp;
        while(!pq.empty())
        {
            tmp=pq.top();
            pq.pop();
            res.append(tmp.first, tmp.second);
        }
        return res;
    }
};