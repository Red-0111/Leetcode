class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& prof, vector<int>& w) {
        int md=*max_element(diff.begin(),diff.end());
        vector<int> mpd(md+1,0);
        for(int i=0;i<diff.size();i++) mpd[diff[i]]=max(mpd[diff[i]],prof[i]);
        for(int i=1;i<=md;i++) mpd[i]=max(mpd[i], mpd[i-1]);
        int tot=0;
        for(int ab:w)
        {
            if(ab>md)
            {
                tot+=mpd[md];
            }
            else
            {
                tot+=mpd[ab];
            }
        }
        return tot;
    }
};