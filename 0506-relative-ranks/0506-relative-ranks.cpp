class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> sc(score.size());
        for(int i=0;i<score.size();i++) sc[i]=make_pair(score[i],i);
        priority_queue<pair<int,int>> pq(sc.begin(),sc.end());
        vector<string> res(score.size());
        int r=1;
        while(!pq.empty())
        {
            auto& idx=pq.top().second;
            if(r==1) res[idx]="Gold Medal";
            else if(r==2) res[idx]="Silver Medal";
            else if(r==3) res[idx]="Bronze Medal";
            else res[idx]=to_string(r);
            r++;
            pq.pop();
        }
        return res;
    }
};