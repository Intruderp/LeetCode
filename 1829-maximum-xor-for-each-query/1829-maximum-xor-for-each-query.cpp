class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int k=0,n=nums.size(),m;
        vector<int> bit(maximumBit,0),ans(n);
        for(int i=0;i<n;i++)
        {
            m=1,k=0;
            for(int b=0;b<maximumBit;b++)
            {
                if((nums[i]&(1<<b)))
                {
                    bit[b]++;
                }
                if(bit[b]%2==0)
                    k+=m;
                m*=2;
            }
            ans[n-i-1]=k;
        }
        return ans;
    }
};