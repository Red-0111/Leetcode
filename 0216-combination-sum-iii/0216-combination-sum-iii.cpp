class Solution {
public:

    void f(vector<vector<int>>& ans, vector<int>& cur,int x, int k, int n)
    {
        if(cur.size()==k&&n==0)
        {
            ans.push_back(cur);
            return ;
        }
        if(x>9||cur.size()>k||n<0) return;
            cur.push_back(x);
            f(ans,cur,x+1,k,n-x);
            cur.pop_back();
            f(ans,cur,x+1,k,n);
        
    }
       
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        f(ans,cur,1,k,n);
        return ans;
    }
};