class Solution {
public:
    int fillCups(vector<int>& amt) {
        priority_queue<int> pq;
        for(auto i:amt) pq.push(i);
        int cnt=0;
        while(pq.top())
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            a--;
            b--;
            pq.push(a);
            pq.push(b);
            cnt++;
        }
        return cnt;
    }
};