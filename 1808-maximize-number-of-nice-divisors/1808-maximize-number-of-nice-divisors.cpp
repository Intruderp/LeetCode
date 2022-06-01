class Solution {
public:
    const int mod=1e9+7;
    long long power(long long a,int n)
    {
        long long res=1;
        while(n)
        {
            if(n%2)
                res=(res*a)%mod;
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<=2)
            return primeFactors;
        int r=primeFactors%3,n=primeFactors/3,res;
        long long p;
        if(r==1)
        {
            p=power(3,n-1);
            res=(p*4)%mod;
        }
        else if(r==2)
        {
            p=power(3,n);
            res=(p*2)%mod;
        }
        else
            res=power(3,n);
        return res;
    }
};