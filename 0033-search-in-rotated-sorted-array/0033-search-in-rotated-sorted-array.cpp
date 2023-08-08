class Solution {
public:
    int search(vector<int>& n, int tar) {
for(int i=0;i<n.size();i++) if(n[i]==tar) return i;
return -1;
    }
};