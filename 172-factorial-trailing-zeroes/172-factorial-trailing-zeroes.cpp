class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2=0,cnt5=0;
        int x=n,p=2;
        while(x/p)
        {
            cnt2+=x/p;
            p*=2;
        }
        p=5;
        while(n/p)
        {
            cnt5+=n/p;
            p*=5;
        }
        return min(cnt2,cnt5);
    }
};