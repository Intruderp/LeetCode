class Solution {
public:
    int largestVariance(string s) 
    {
        int res=0;
        for(char c='a';c<='z';c++)
        {
            for(char c2='a';c2<='z';c2++)
            {
                if(c==c2)
                    continue;
                int maxSum=0;
                bool flag=false,flag2=false;
                for(char &ch:s)
                {
                    if(ch==c)
                        maxSum+=1;
                    else if(ch==c2)
                    {
                        flag=true;
                        maxSum-=1;
                    }
                    else
                        continue;
                    if(maxSum<0)
                    {
                        flag2=true;
                        maxSum=0;
                        flag=false;
                    }
                    if(flag)
                        res=max(res,maxSum);
                    else if(flag2)
                        res=max(res,maxSum-1);
                }
            }
        }
        return res;
    }
};