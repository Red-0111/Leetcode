class Solution {
public:
vector<vector<int>> ans;

    void f(int s,vector<int>& arr, vector<int>&cur, int tar)
    {
        if(tar==0)
        {
            ans.push_back(cur);
            return;
        }
        for(int i=s;i<arr.size();i++)
        {
            if(i>s&&(arr[i]==arr[i-1])) continue;
            if(arr[i]>tar) continue;
            cur.push_back(arr[i]);
            f(i+1,arr,cur,tar-arr[i]);
            cur.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin(),arr.end());
        vector<int> cur;
        f(0,arr,cur,tar);
        return ans;
    }
};