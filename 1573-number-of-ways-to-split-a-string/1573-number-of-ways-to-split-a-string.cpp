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
            int i=0,j=n-1,start=0,end=0,x=1,y=1;
            while(end<ones/3)
            {
                end+=s[j]=='1';
                j--;
            }
            while(s[j]!='1')
            {
                y++;
                j--;
            }
            while(start<ones/3)
            {
                start+=s[i]=='1';
                i++;
            }
            while(s[i]=='0')
            {
                x++;
                i++;
            }
            res=((long)x*y)%mod;
        }
        return res;
    }
};