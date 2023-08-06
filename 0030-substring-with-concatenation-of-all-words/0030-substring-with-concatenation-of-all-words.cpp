class Solution {
public:

    bool check(unordered_map<string, int> wc, string s, int wl)
    {
        for(int j=0;j<s.size();j+=wl)
        {
            string w=s.substr(j,wl);
            if(wc.find(w)!=wc.end())
            {
                if(--wc[w]==-1) return false;
            }
            else return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wl=words[0].size();
        int slen=s.size();
        int ww=words.size()*wl;

        unordered_map<string,int> wc;
        for(int i=0;i<words.size();i++) wc[words[i]]++;
        int i=0;
        while(i+ww<=slen){
             if(check(wc,s.substr(i,ww),wl)) res.push_back(i);
             i++;
        }
        return res;
    }
};