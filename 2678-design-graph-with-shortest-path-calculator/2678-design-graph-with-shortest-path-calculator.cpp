class Graph {
    vector<vector<int>> dist;
    int n;
    const int mv=500000000;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        dist=vector<vector<int>>(n,vector<int>(n,mv));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(auto e:edges) dist[e[0]][e[1]]=e[2];
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        } 
    }
    
    void addEdge(vector<int> e) {
        if(dist[e[0]][e[1]]<=e[2]) return;
        dist[e[0]][e[1]]=e[2];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][e[0]]+e[2]+dist[e[1]][j]);
            }
        }
    }
    
    int shortestPath(int n1, int n2) {
        if(dist[n1][n2]==mv) return -1;
        return dist[n1][n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */