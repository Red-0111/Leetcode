class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pro, vector<int>& cap) {
        int n=pro.size();
        vector<pair<int,int>> proj;
        for(int i=0;i<n;i++) proj.emplace_back(cap[i],pro[i]);
        sort(proj.begin(),proj.end());
        priority_queue<int> mh;
        int i=0;
        for(int j=0;j<k;j++)
        {
            while(i<n&&proj[i].first<=w)
            {
                mh.push(proj[i].second);
                i++;
            }
            if(mh.empty()) break;
            w+=mh.top();
            mh.pop();
        }
        return w;
    }
};