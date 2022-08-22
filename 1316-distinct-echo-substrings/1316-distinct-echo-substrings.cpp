class Solution {
private:
    vector<int> inv;
    long long p=1;
    int power=31,mod=1e9+7;
    int inverse(long long a)
    {
        int n=mod-2;
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
public:
    Solution()
    {
        inv.resize(2000);
        for(int i=0;i<2000;i++)
        {
            inv[i]=inverse(p);
            p=(power*p)%mod;
        }
    }
    int distinctEchoSubstrings(string &text) 
    {
        int n=text.length(),res=0;
        long long hash=0,h1,h2;
        p=1;
        unordered_set<int> vis;
        for(int i=0;i<n;i++)
        {
            hash=0,p=1;
            vector<int> dp;
            for(int j=i;j<n;j++)
            {
                hash=(hash+(text[j]-'a'+1)*p)%mod;
                p=(p*power)%mod;
                dp.push_back(hash);
                if(dp.size()%2==0 and vis.count(hash)==0)
                {
                    h1=dp[dp.size()/2-1];
                    h2=(dp.back()-h1+mod)%mod;
                    h2=(h2*inv[dp.size()/2])%mod;
                    if(h1==h2)
                    {
                        res++;
                        vis.insert(hash);
                    }
                }
            }
        }
        return res;
    }
};