class Solution {
public:
    bool check(vector<int> &nums,int threshold,int &div)
    {
        for(auto &num:nums)
        {
            threshold-=(num+div-1)/div;
            if(threshold<0)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int low=1,high=1e6,smallestDiv=high,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(check(nums,threshold,mid))
            {
                smallestDiv=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return smallestDiv;
    }
};