class Solution {
public:
    bool help(int cur,int power,int mx)
    {
        if(cur==0)
            return true;
        if(cur<0 or power>mx)
            return false;
        return help(cur-power,power*3,mx) or help(cur,power*3,mx);
    }
    bool checkPowersOfThree(int n) {
        return help(n,1,n);
    }
};