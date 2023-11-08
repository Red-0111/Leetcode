class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy) return t!=1;
        if(abs(fx-sx)>abs(fy-sy)) return t>=abs(fx-sx);
        else return t>=abs(fy-sy);
        return false;
    }
};