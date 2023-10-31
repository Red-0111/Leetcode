class Solution {
public:

    bool check(string s, string goal, int idx)
    {
        int n=s.length();
        for(int i=1;i<n;i++)
        {
            if(s[i]!=goal[(i+idx)%n]) return false;
        }
        return true;
    }

    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[0]==goal[i])
            {
                if(check(s,goal,i)) return true;
            }
        }
        return false;
    }
};