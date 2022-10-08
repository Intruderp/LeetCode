class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) 
    {
        int ans=1e9,j,k,sum,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            j=i+1,k=n-1;
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-t)<abs(ans-t))
                    ans=sum;
                if(sum>t)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};