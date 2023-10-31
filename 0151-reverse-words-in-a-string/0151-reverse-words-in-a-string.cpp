class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word, res;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                word+=s[i];
            }
            else
            {
                if(!word.empty())
                {
                    st.push(word);
                    word="";
                }
            }
        }
        if(!word.empty()) st.push(word);
        while(!st.empty())
        {
            res+=st.top()+" ";
            st.pop();
        }
        res.pop_back();
        return res;
    }
};