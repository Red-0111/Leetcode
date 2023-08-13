class Solution {
public:
char tb[16]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    uint32_t reverseBits(uint32_t n) {
        int c=0;
        uint32_t ret=0;
        uint32_t msk=0xF;
        for(int i=0;i<8;i++)
        {
            ret=ret<<4;
            c=msk&n;
            ret|=tb[c];
            n=n>>4;
        }
        return ret;
    }
};