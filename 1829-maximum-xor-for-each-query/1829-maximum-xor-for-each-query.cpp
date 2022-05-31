class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        vector<int> bit(maximumBit,0),ans;
        int k=0,n=nums.size(),m;
        for(int &num:nums)
        {
            for(int i=0;i<maximumBit;i++)
            {
                if((num&(1<<i)))
                    bit[i]++;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            k=0;
            m=1;
            for(int b=0;b<maximumBit;b++)
            {
                if(bit[b]%2==0)
                    k+=m;
                m*=2;
            }
            ans.push_back(k);
            for(int b=0;b<maximumBit;b++)
            {
                if((nums[i]&(1<<b)))
                    bit[b]--;
            }
        }
        return ans;
    }
};