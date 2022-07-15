class Solution {
public:
    int n;
    void help(int i,int x,int sum,int rem,vector<vector<int>> &v,vector<int> &nums)
    {
        v[x].push_back(sum);
        if(rem==0)
            return ;
        help(i+1,x,sum,rem-1,v,nums);
        help(i+1,x+1,sum+nums[i],rem-1,v,nums);
    }
    int minimumDifference(vector<int>& nums) 
    {
        n=nums.size()/2;
        vector<vector<int>> a(n+1),b(n+1);
        help(0,0,0,n,a,nums);
        help(n,0,0,n,b,nums);
        int res=INT_MAX,sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<=n;i++)
        {
            sort(b[i].begin(),b[i].end());
        }
        for(int i=0;i<=n;i++)
        {
            for(int &x:a[i])
            {
                auto it=lower_bound(b[n-i].begin(),b[n-i].end(),(sum/2-x));
                if(it==b[n-i].end())
                    it--;
                res=min(res,abs(2*(x+*it)-sum));
                if(it!=b[n-i].begin())
                {
                    it--;
                    res=min(res,abs(2*(x+*it)-sum));
                }
            }
        }
        return res;
    }
};