class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int tar) {
        if(source==tar) return 0;
        unordered_map<int,vector<int>>stb;
        for(int i=0;i<routes.size();i++)
        {
            for(int s:routes[i]) stb[s].push_back(i);
        }
        queue<pair<int,int>> bfsq;
        unordered_set<int> visst;
        unordered_set<int> visbs;
        bfsq.push({source,0});
        visst.insert(source);
        while(!bfsq.empty())
        {
            int curs=bfsq.front().first;
            int stps=bfsq.front().second;
            bfsq.pop();
            for(int b:stb[curs])
            {
                if(visbs.count(b)==0)
                {
                    visbs.insert(b);
                    for(int nxts:routes[b])
                    {
                        if(visst.count(nxts)==0)
                        {
                            if(nxts==tar) return stps+1;
                            bfsq.push({nxts,stps+1});
                            visst.insert(nxts);
                        }
                    }
                }
            }
        }
        return -1;
    }
};