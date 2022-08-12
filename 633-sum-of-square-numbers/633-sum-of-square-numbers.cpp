class Solution {
public:
    bool check(int x)
    {
        int low=0,high=x;
        long mid;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(mid*mid==x)
                return true;
            if(mid*mid>x)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
    bool judgeSquareSum(int c) 
    {
        for(long i=0;i*i<=c;i++)
        {
            if(check(c-i*i))
                return true;
        }
        return false;
    }
};