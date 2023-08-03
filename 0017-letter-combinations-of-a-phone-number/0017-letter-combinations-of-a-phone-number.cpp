class Solution {
public:

    void solve(string dig,string out, int ind,vector<string>&ans,string map[])
    {
        if(ind>=dig.length())
        {
            ans.push_back(out);
            return;
        }

        int num=dig[ind]-'0';
        string val=map[num];
        for(int i=0;i<val.length();i++)
        {
            out.push_back(val[i]);
            solve(dig,out,ind+1,ans,map);
            out.pop_back();
        }
    }
    
    vector<string> letterCombinations(string dig) {
       vector<string> ans;
       if(dig.length()==0) return ans;
       string out;
       string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       solve(dig,out,0,ans,map);
       return ans;
    }
};