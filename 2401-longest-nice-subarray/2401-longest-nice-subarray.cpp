class Solution {
public:
    bool check(int i,int j,vector<int> &nums)
    {
        for(int x=i;x<=j;x++)
        {
            for(int y=x+1;y<=j;y++)
            {
                if(nums[x]&nums[y])
                    return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int res=1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if((nums[i]&nums[j])==0 and check(i,j,nums))
                    res=max(res,j-i+1);
                else 
                    break;
            }
        }
        return res;
    }
};