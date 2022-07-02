class Solution {
public:
    int n;
    bool check(vector<int>&b,int x,int m,int k)
    {
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]<=x)
                cur++;
            else
                cur=0;
            if(cur==k)
            {
                m--;
                cur=0;
            }
        }
        return m<=0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        n=bloomDay.size();
        int res=-1,l=1,h=1e9,mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(check(bloomDay,mid,m,k))
            {
                h=mid-1;
                res=mid;
            }
            else
                l=mid+1;
        }
        return res;
    }
};