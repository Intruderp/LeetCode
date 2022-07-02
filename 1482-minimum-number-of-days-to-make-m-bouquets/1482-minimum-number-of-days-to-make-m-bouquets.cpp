class Solution {
public:
    int n;
    bool check(vector<int>&b,int x,int m,int k)
    {
        vector<int> notBloomed;
        for(int i=n-1;i>=0;i--)
        {
            if(b[i]>x)
                notBloomed.push_back(i);
        }
        for(int i=0;i<n;)
        {
            if(notBloomed.size() and notBloomed.back()<=i+k-1)
                i++;
            else
            {
                m--;
                i+=k;
            }
            while(notBloomed.size() and notBloomed.back()<i)
                notBloomed.pop_back();
            if(m==0 and i<=n)
                return true;
        }
        return false;
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