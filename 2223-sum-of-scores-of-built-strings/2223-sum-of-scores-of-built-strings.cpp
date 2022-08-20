class Solution {
private:
    const int mod=1e9+9;
    int inverse(long long a)
    {
        long long inv=1,n=mod-2;
        while(n)
        {
            if(n%2)
                inv=(inv*a)%mod;
            a=(a*a)%mod;
            n/=2;
        }
        return inv;
    }
public:
    long long sumScores(string s)
    {
        int p=31,n=s.length(),low,high,mid,len;
        long long res=n,power=1,hash=0;
        vector<int> dp(n,0),inv(n);
        for(int i=0;i<n;i++)
        {
            hash=(hash+(s[i]-'a'+1)*power)%mod;
            dp[i]=hash;
            inv[i]=inverse(power);
            power=(power*p)%mod;
        }
        for(int i=n-1;i>0;i--)
        {
            low=i,high=n-1,len=0;
            while(low<=high)
            {
                mid=(low+high)/2;
                hash=(dp[mid]-dp[i-1]+mod)%mod;
                hash=(hash*inv[i])%mod;
                if(dp[mid-i]==hash)
                {
                    len=mid-i+1;
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            res+=len;
        }
        return res;
    }
};