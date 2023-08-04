class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int s=0;
        int e=m.size()-1;
        while(s<e)
        {
            for(int i=0;i<e-s;i++)
            {
                swap(m[s][s+i],m[e-i][s]);
                swap(m[e-i][s],m[e][e-i]);
                swap(m[e][e-i],m[s+i][e]);
            }
            s++;
            e--;
        }
    }
};