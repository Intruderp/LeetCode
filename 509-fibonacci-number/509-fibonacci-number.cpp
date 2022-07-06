class Solution {
public:
    int fib(int n)
    {
        if(n<2)
            return n;
        int a=0,b=1,ans;
        for(int i=2;i<=n;i++)
        {
            ans=a+b;
            if(i==n)
                return ans;
            a=b;
            b=ans;
        }
        return 0;
    }
};