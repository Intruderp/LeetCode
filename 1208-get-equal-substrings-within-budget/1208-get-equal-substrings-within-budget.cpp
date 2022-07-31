class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n=s.length(),res=0,low,high,mid,reqCost;
        vector<int> pre(n,0);
        pre[0]=abs(s[0]-t[0]);
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1]+abs(s[i]-t[i]);
        for(int i=0;i<n;i++)
        {
            low=i,high=n-1;
            while(low<=high)
            {
                mid=(high+low)/2;
                reqCost=pre[mid];
                if(i>0)
                    reqCost-=pre[i-1];
                if(reqCost<=maxCost)
                {
                    res=max(res,mid-i+1);
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
        }
        return res;
    }
};