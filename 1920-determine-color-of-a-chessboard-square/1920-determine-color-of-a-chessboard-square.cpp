class Solution {
public:
    bool squareIsWhite(string coord) {
        int c=coord[0]-'a'+1;
        int d=coord[1]-'1';
        if((c%2==0&&d%2==0)||(c%2!=0&&d%2!=0)) return true;
        else return false;
    }
};