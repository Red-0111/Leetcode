class Solution {
public:
    int poorPigs(int b, int mtd, int mtt) {
        return ceil(log2(b)/log2(int(mtt/mtd)+1));
    }
};