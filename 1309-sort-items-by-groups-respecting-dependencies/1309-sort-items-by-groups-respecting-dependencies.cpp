class Solution {
public:

    vector<int> ts(unordered_map<int,vector<int>>& g, vector<int>& ind)
    {
        vector<int> vis;
        stack<int> st;
        for(int i=0;i<ind.size();i++)
        {
            if(ind[i]==0) st.push(i);
        }

        while(!st.empty())
        {
            int cur=st.top();
            st.pop();
            vis.push_back(cur);

            for(int n: g[cur])
            {
                ind[n]--;
                if(ind[n]==0) st.push(n);
            }
        }
        return vis.size()==g.size()?vis:vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& gr, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++)
        {
            if(gr[i]==-1) gr[i]=m++;
        }
        unordered_map<int,vector<int>> ig;
        vector<int> ideg(n,0);
        for(int i=0;i<n;i++)
        {
            ig[i]=vector<int>();
        }

        unordered_map<int,vector<int>>gg;
        vector<int> gdeg(m,0);
        for(int i=0;i<m;i++)
        {
            gg[i]=vector<int>();
        }
        for(int i=0;i<n;i++)
        {
            for(int p:beforeItems[i])
            {
                ig[p].push_back(i);
                ideg[i]++;
                if(gr[i]!=gr[p])
                {
                    gg[gr[p]].push_back(gr[i]);
                    gdeg[gr[i]]++;
                }
            }
        }
        vector<int> io=ts(ig,ideg);
        vector<int> go=ts(gg,gdeg);

        if(io.empty()||go.empty()) return vector<int>();
        unordered_map<int,vector<int>> og;
        for(int it:io) og[gr[it]].push_back(it);

        vector<int> ans;
        for(int et:go) ans.insert(ans.end(),og[et].begin(),og[et].end());
        return ans;
    }
};