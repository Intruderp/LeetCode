class Solution {
public:
    bool poss(char c1,char c2)
    {
        int x=(c1-'0')*10+(c2-'0');
        return x<=26;
    }
    int numDecodings(string s)
    {
        int n=s.length();
        if(s[0]=='0')
            return 0;
        int prev1,prev2;
        if(n==1)
            return 1;
        prev2=1;
        if(s[1]!='0')
        {
            prev1=1+poss(s[0],s[1]);
        }
        else
        {
            prev1=poss(s[0],s[1]);
        }
        int res=prev1;
        for(int i=2;i<n;i++)
        {
            res=0;
            if(s[i]=='0')
            {
                if(s[i-1]!='0' and poss(s[i-1],'0'))
                    res=prev2;
            }
            else
            {
                res=prev1;
                if(s[i-1]!='0' and poss(s[i-1],s[i]))
                    res+=prev2;
            }
            prev2=prev1;
            prev1=res;
        }
        return res;
    }
    
};