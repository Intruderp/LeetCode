class Solution {
public:
    string longestPrefix(string s) 
    {
        long power=1,p=31,hash=0,hash2=0,mod=1e9+7,n=s.length(),len=0,p2=33,power2=1;
        set<pair<int,int>> h;
        for(char &c:s)
        {
            hash=(hash+(c-'a'+1)*power)%mod;
            power=(power*p)%mod;
            hash2=(hash2+(c-'a'+1)*power2)%mod;
            power2=(power2*p2)%mod;
            h.insert({hash,hash2});
        }
        hash=0;
        hash2=0;
        for(int i=n-1;i>0;i--)
        {
            hash=(hash*p)%mod;
            hash=(hash+(s[i]-'a'+1))%mod;
            hash2=(hash2*p2)%mod;
            hash2=(hash2+(s[i]-'a'+1))%mod;
            if(h.count({hash,hash2}))
                len=n-i;
        }
        return s.substr(0,len);
    }
};