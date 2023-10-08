class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nin) {
        int n=in.size();
        vector<vector<int>> ans;
        int ii=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nin[0]>in[i][0])
            {
                ii=i+1;
                break;
            }
        }
        in.push_back(nin);
        for(int i=(n+1)-1;i>ii;i--) swap(in[i],in[i-1]);
        ans.push_back(in[0]);
        int l;
        for(int i=1;i<n+1;i++)
        {
            if(ans.back()[1]<in[i][0]) ans.push_back(in[i]);
            else if(ans.back()[1]>=in[i][0])
            {
                l=max(ans.back()[1],in[i][1]);
                ans.back()[1]=l;
            }
        }
        return ans;
    }
};