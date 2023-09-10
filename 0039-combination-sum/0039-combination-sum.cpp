class Solution {
public:
    vector<vector<int>> ans;

    void x(int i, vector<int>&arr, vector<int>& temp, int tar)
    {
        if(tar==0)
        {
            ans.push_back(temp);
            return;
        }
        if(tar<0) return;
        if(i==arr.size()) return;
        x(i+1,arr,temp,tar);
        temp.push_back(arr[i]);
        x(i,arr,temp,tar-arr[i]);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int> temp;
        x(0,arr,temp,tar);
        return ans;
    }
};