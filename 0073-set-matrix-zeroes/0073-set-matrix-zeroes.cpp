class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>> temp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0) temp.push_back(make_pair(i,j));
            }
        }

        for(int i=0;i<temp.size();i++)
        {
            int r=temp[i].first;
            int c=temp[i].second;
            for(int j=0;j<mat.size();j++)
            {
                for(int k=0;k<mat[j].size();k++)
                {
                    if(j==r) mat[j][k]=0;
                    else if(k==c) mat[j][k]=0;
                }
            }
        }
        
    }
};