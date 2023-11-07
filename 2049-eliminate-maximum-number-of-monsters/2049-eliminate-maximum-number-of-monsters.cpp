class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> t(dist.size());
        for(int i=0;i<dist.size();i++) t[i]=ceil(dist[i]/double(speed[i]));
        sort(t.begin(),t.end());
        int cnt=0;
        int te=0;
        for(int&i:t)
        {
            if(te>0&&i-te<=0) return cnt;
            te++;
            cnt++;
        }
        return cnt;
    }
};