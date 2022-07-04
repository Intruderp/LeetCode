class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.length(),countOne=0,countZero=0;
        long long res=0,resOne=0,resZero=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                res+=resZero;
                resOne+=countZero;
                countOne++;
            }
            else
            {
                res+=resOne;
                resZero+=countOne;
                countZero++;
            }
        }
        return res;
    }
};