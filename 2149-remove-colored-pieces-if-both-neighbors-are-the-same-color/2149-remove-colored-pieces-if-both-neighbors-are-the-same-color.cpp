class Solution {
public:
    bool winnerOfGame(string c) {
        int a=0, b=0;
        for(int i=1;i<c.size();i++)
        {
            char cc=c[i];
            char pc=c[i-1];
            char nc=c[i+1];
            if(cc=='A'&&pc=='A'&&nc=='A') a++;
            else if(cc=='B'&&pc=='B'&&nc=='B') b++;
        }
        return a>b;
    }
};