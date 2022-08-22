class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if(n<=0)
            return false;
        float exp=log2(n);
        if(exp-floor(exp)==0)
            return (int)exp%2==0;
        return false;
    }
};