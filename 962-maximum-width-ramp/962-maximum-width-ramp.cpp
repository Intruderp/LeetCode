class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        vector<int> stack;
        int res=0,low,mid,high,posn,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(stack.size()==0 or nums[stack.back()]>nums[i])
                stack.push_back(i);
            low=0,high=stack.size()-1,posn=-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(nums[stack[mid]]<=nums[i])
                {
                    posn=stack[mid];
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            if(posn!=-1)
                res=max(res,i-posn);
        }
        return res;
    }
};