class Solution {
public:
    int largestInteger(int num) {
        vector<int> v;
        long long int temp=num;
        while(num)
        {
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(), v.end());
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%2==0) v1.push_back(v[i]);
            else v2.push_back(v[i]);
        }
        sort(v1.begin(),v1.end(),greater<int>());
        sort(v2.begin(),v2.end(),greater<int>());
        int k=0;
        int c=0;
        for(int i=0;i<v.size();i++) if(v[i]%2==0) v[i]=v1[k++]; else v[i]=v2[c++];
        temp=0;
        for(int i=0;i<v.size();i++){
            temp+=v[i];
            temp*=10;
        }
        return temp/10;
    }
};