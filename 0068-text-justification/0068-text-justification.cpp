class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxl) {
        vector<string> res;
        vector<string> cur;
        int numlen=0;
        for(string word:words)
        {
            if(word.size()+cur.size()+numlen>maxl)
            {
                for(int i=0;i<maxl-numlen;i++)
                {
                    cur[i%(cur.size()-1?cur.size()-1:1)]+=' ';
                }
                res.push_back("");
                for(string s:cur) res.back()+=s;
                cur.clear();
                numlen=0;
            }
            cur.push_back(word);
            numlen+=word.size();
        }
        string lasl="";
        for(string s:cur) lasl+=s+' ';
        lasl=lasl.substr(0,lasl.size()-1);
        while(lasl.size()<maxl) lasl+=' ';
        res.push_back(lasl);
        return res;
    }
};