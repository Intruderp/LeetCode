class Solution {
private: 
    bool check(vector<int> &weights,int x,int n,int days)
    {
        int cur=0,req=1;
        for(int i=0;i<n;i++)
        {
            if(cur+weights[i]<=x)
            {
                cur+=weights[i];
            }
            else
            {
                req++;
                cur=weights[i];
            }
            if(req>days)
                return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n=weights.size(),low=*max_element(weights.begin(),weights.end()),high=n*500,mid,res=-1;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(check(weights,mid,n,days))
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