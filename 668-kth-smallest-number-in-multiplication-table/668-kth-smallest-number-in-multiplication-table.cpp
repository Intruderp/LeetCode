class Solution {
public:
    bool check(int &n,int &m,int &x,int &k)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=min(m,x/i);
            if(cnt>=k)
                return true;
        }
        return false;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int low=1,high=m*n,mid,res=1;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(check(n,m,mid,k))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};