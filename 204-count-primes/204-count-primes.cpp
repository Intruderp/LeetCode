class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        vector<int> prime(n+1,1);
        int res=n/2;
        for(int i=3;i*i<n;i+=2)
        {
           if(prime[i])
           {
               for(int j=i*i;j<n;j+=i)
               {
                   if(j%2 and prime[j])
                       res--;
                   prime[j]=0;
               }
           }
        }
        return res;
    }
};