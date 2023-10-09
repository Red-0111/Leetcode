class Solution {
public:

    void x(string& s, vector<string>& ans,string cur,int ind, int cnt)
    {
        if(cnt==4&&(s.length()==ind)){
            ans.push_back(cur);    
            return;
        }
        if((s.length()-ind)>3*(4-cnt)||ind>=s.length()) return;
        for(int i=1;i<=3;i++)
        {
            string cursec=s.substr(ind,i);
            if((cursec.length()>1&&cursec[0]=='0')||stoi(cursec)>255) continue;
            string tmp=cnt==0?cursec:(cur+"."+cursec);
            x(s,ans,tmp,ind+i,cnt+1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        x(s,ans,"",0,0);
        return ans;
    }
};