class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int tar) {
        int rows=m.size();
        int cols=m[0].size();
        int row=0, col=cols-1;
        while(row<rows&&col>-1)
        {
            int c=m[row][col];
            if(c==tar) return true;
            else if(tar>c) row++;
            else col--;
        }
        return false;
    }
};