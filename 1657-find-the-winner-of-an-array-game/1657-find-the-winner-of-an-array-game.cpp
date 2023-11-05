class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>arr.size()) return *max_element(arr.begin(),arr.end());
        int cur_win=arr[0], win_cnt=0, ptr=1;
        while(win_cnt<k&&ptr<arr.size())
        {
            if(cur_win==max(arr[0],arr[ptr]))
            {
                win_cnt++;
                ptr++;
            }
            else
            {
                win_cnt=1;
                cur_win=arr[ptr];
                ptr++;
                arr[0]=cur_win;
            }
        }
        return cur_win;
    }
};