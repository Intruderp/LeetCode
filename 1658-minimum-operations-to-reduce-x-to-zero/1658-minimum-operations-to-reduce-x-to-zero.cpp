class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0,cnt=0,n=nums.size(),ans=n+1;
        unordered_map<int,int> m;
        for(int i=n-1;i>=0;i--)
        {
            sum+=nums[i];
            m[sum]=i;
        }
        for(int i=0;i<n;i++)
        {
            if(m.count(x) and m[x]>=i)
                ans=min(ans,i+n-m[x]);
            x-=nums[i];
            if(x==0)
                ans=min(ans,i+1);
            else if(x<0)
                break;
        }
        return ans==n+1 ? -1:ans;
    }
};