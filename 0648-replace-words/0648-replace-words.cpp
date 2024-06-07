class Solution {
public:
    string replaceWords(vector<string>& dic, string s) {
        string ans="", word="";
        set<string> st;
        s+=' ';
        for(auto i:dic) st.insert(i);
        for(auto i:s)
        {
            if(i==' '){
                if(ans.size()>0) ans+=' ';
                string tmp="";
                for(auto j: word)
                {
                    tmp+=j;
                    if(st.count(tmp)) break;
                }
                ans+=tmp;
                word="";
            }
            else word+=i;
        }
        return ans;

    }
};