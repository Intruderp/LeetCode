class Solution {
public:
    int help(vector<int>& nums, int firstLen, int secondLen)
    {
        int ans=0,sum,n=nums.size(),mx=0;
        vector<int> suff(n,0),pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1]+nums[i];
        for(int i=n-secondLen;i>=0;i--)
        {
            sum=pre[i+secondLen-1];
            if(i>0)
                sum-=pre[i-1];
            mx=max(mx,sum);
            suff[i]=mx;
        }
        for(int i=0;i<=n-firstLen-secondLen;i++)
        {
            sum=pre[i+firstLen-1]+suff[i+firstLen];
            if(i>0)
                sum-=pre[i-1];
            ans=max(ans,sum);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) 
    {
        return max(help(nums,firstLen,secondLen),help(nums,secondLen,firstLen));
    }
};