class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cntx=0,cnty=0,n=s1.length();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                cntx+=s1[i]=='x';
                cnty+=s1[i]=='y';
            }
        }
        if((cntx+cnty)%2)
            return -1;
        int res=cntx/2+cnty/2;
        if(cntx%2)
            res+=2;
        return res;
    }
};