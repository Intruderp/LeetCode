class Solution {
public:
    int numWays(string s) {
        int ones=0;
        for(auto &c:s)
        {
            ones+=c=='1';
        }
        int n=s.length(),res=0,mod=1e9+7;
        if(ones==0)
        {
            long x=n-2;
            res=(x*(x+1)/2)%mod;
        }
        else if(ones%3==0)
        {
            int req=ones/3,ways1=0,ways2=0,cnt=0;
            for(auto &c:s)
            {
                cnt+=c=='1';
                if(cnt==req)
                    ways1++;
                else if(cnt==req*2)
                    ways2++;
            }
            res=((long)ways1*ways2)%mod;
        }
        return res;
    }
};