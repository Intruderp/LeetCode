class Solution {
public:
    int hammingWeight(uint32_t n) {
        int setBits=0;
        for(int i=0;i<32;i++)
        {
            setBits+=((1<<i)&n)>=1;
        }
        return setBits;
    }
};