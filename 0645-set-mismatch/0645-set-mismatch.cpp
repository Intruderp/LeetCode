class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int n=nums.size(),sum=(n+1)*n/2,mNum,rNum,sum2=0;
        for(int i=0;i<n;i++)
        {
            sum2+=abs(nums[i]);
            if(nums[abs(nums[i])-1]<0)
                rNum=abs(nums[i]);
            nums[abs(nums[i])-1]*=-1;
        }
        return vector<int>{rNum,sum-sum2+rNum};
    }
};