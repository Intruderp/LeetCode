class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) 
    {
        int n=s.length(),i=n-k,posn=-1;
        long long hash=0,p=1;
        for(int j=i;j<n;j++)
        {
            hash=(hash+(s[j]-'a'+1)*p)%modulo;
            if(j!=n-1)
                p=(p*power)%modulo;
        }
        if(hash==hashValue)
            posn=i;
        i--;
        while(i>=0)
        {
            hash=(hash-((s[i+k]-'a'+1)*p)%modulo+modulo)%modulo;
            hash=(hash*power)%modulo;
            hash=(hash+(s[i]-'a'+1))%modulo;
            if(hash==hashValue)
                posn=i;
            i--;
        }
        return s.substr(posn,k);
    }
};