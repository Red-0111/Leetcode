/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int fpi(int l, int h, MountainArray &m)
    {
        while(l!=h)
        {
            int mi=l+(h-l)/2;
            if(m.get(mi)<m.get(mi+1)) l=mi+1;
            else h=mi;
        }
        return l;
    }

    int bs(int l, int h, int tar, MountainArray &m, bool rev)
    {
        while(l!=h)
        {
            int mi=l+(h-l)/2;
            if(rev)
            {
                if(m.get(mi)>tar) l=mi+1;
                else h=mi;
            }
            else
            {
                if(m.get(mi)<tar) l=mi+1;
                else h=mi;
            }
        }
        return l;
    }

    int findInMountainArray(int tar, MountainArray &m) {
        int l=m.length();
        int pind=fpi(1,l-2,m);
        int inci=bs(0,pind,tar,m,false);
        if(m.get(inci)==tar) return inci;

        int dec=bs(pind+1,l-1,tar,m,true);
        if(m.get(dec)==tar) return dec;
        return -1;
    }
};