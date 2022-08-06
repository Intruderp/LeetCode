class Solution {
private:
    bool check(vector<int> &nums,int x,int maxOperations)
    {
        int op=0;
        for(auto &num:nums)
        {
            if(num>x)
            {
                op+=(num-1)/x;
                if(op>maxOperations)
                    return false;
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int low=1,high=1e9,mid,penalty=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(check(nums,mid,maxOperations))
            {
                penalty=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return penalty;
    }
};