class Solution {
public:
    vector<long> hash,inv;
    int dp[4005];
    const int mod=1e9+7;
    int powerr(long a,int n)
    {
        long res=1;
        while(n)
        {
            if(n%2)
            {
                res=(res*a)%mod;
            }
            n/=2;
            a=(a*a)%mod;
        }
        return res;
    }
    int help(int i,int n)
    {
        if(n==0)
            return 0;
        int ans=0;
        if(dp[i]!=-1)
            return dp[i];
        for(int l=1;l<=n/2;l++)
        {
            long h1,h2;
            h1=((hash[i+l-1]-(i>0 ? hash[i-1]:0)+mod)*inv[i])%mod;
            h2=((hash[i+l*2-1]-hash[i+l-1]+mod)*inv[i+l])%mod;
            if(h1==h2)
                ans=max(ans,help(i+l,n-l)+1);
        }
        return dp[i]=max(ans,help(n,0)+1);
    }
    int deleteString(string s) 
    {
        int n=s.length();
        hash.resize(n);
        inv.resize(n);
        long p=31,power=1;
        inv[0]=1;
        hash[0]=(s[0]-'a'+1);
        for(int i=1;i<n;i++)
        {
            power=(power*p)%mod;
            inv[i]=powerr(power,mod-2);
            hash[i]=(hash[i-1]+(s[i]-'a'+1)*power)%mod;
        }
        memset(dp,-1,sizeof(dp));
        return help(0,n);
    }
};