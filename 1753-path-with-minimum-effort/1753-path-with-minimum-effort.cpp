class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        int dis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j]=INT_MAX;
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int e=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1&&y==m-1) return e;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=x+dx[i];
                int nc=y+dy[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m)
                {
                    int ne=max(e,abs(h[nr][nc]-h[x][y]));
                    if(ne<dis[nr][nc])
                    {
                        dis[nr][nc]=ne;
                        pq.push({ne,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};