class Solution {
public:
    string longestPrefix(string s) 
    {
        int n=s.length(),p=31,mod=1e9+7,len=0;
        long prefixHash=0,suffixHash=0,power=1;
        for(int i=0;i<n-1;i++)
        {
            prefixHash=(prefixHash+(s[i]-'a'+1)*power)%mod;
            suffixHash=(suffixHash*p)%mod;
            suffixHash=(suffixHash+(s[n-i-1]-'a'+1))%mod;
            power=(power*p)%mod;
            if(suffixHash==prefixHash)
                len=i+1;
        }
        return s.substr(0,len);
    }
};