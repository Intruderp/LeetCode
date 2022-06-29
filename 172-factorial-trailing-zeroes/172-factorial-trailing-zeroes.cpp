class Solution {
public:
    int trailingZeroes(int n) {
        int res=0,m=5;
        while(n/m)
        {
            res+=n/m;
            m*=5;
        }
        return res;
    }
};