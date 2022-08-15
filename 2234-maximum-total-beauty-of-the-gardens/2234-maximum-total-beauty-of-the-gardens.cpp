class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, long long full, long long partial) 
    {
        long long res=0,req,cur,rem,low,high,mid,poss;
        int n=flowers.size(),i=n-1;
        sort(flowers.begin(),flowers.end());
        vector<long long> pre(n,0);
        pre[0]=flowers[0];
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1]+flowers[i];
        while(i>=0 and flowers[i]>=target)
            i--;
        while(i>=0)
        {
            low=flowers[0],high=target-1;
            poss=-1;
            cur=0;
            while(low<=high)
            {
                mid=(high+low)/2;
                auto it=upper_bound(flowers.begin(),flowers.begin()+i+1,mid);
                it--;
                req=(mid)*(it-flowers.begin()+1)-pre[it-flowers.begin()];
                if(req<=newFlowers)
                {
                    poss=mid;
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            res=max(res,full*(n-i-1)+partial*poss);
            newFlowers-=(target-flowers[i]);
            if(newFlowers<0)
                break;
            i--;
        }
        if(newFlowers>=0)
            res=max(res,n*full);
        return res;
    }
};