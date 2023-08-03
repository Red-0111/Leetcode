class Solution {
public:
    vector<string> readBinaryWatch(int n) {
        vector<string> res;
        for(int h=0;h<12;h++)
        {
            for(int m=0;m<60;m++)
            {
                string tmp="";
                if(__builtin_popcount(h)+__builtin_popcount(m)==n)
                {
                    tmp+=to_string(h)+":";
                    if(m<10) tmp+="0";
                    tmp+=to_string(m);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};