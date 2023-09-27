class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<long long> cl;
        cl.push(0);
        for(size_t i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
            {
                long long l=cl.top()*(s[i]-'0');
                cl.push(l);
            }
            else
            {
                long long l=cl.top()+1;
                cl.push(l);
            }
        }
        size_t ln=cl.size();
        while(!cl.empty())
        {
            k%=cl.top();
            ln--;
            if(k==0&&isalpha(s[ln-1])) return string(1,s[ln-1]);
            cl.pop();
        }
        return "";
    }
};