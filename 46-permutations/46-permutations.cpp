class Solution {
public:
    int n;
    bool nextPermutation(vector<int> &nums)
    {
        int ind=-1,ind2=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                ind=i-1;
                break;
            }
        }
        if(ind==-1)
            return false;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[ind])
            {
                ind2=i;
                break;
            }
        }
        swap(nums[ind],nums[ind2]);
        reverse(nums.begin()+ind+1,nums.end());
        return true;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<vector<int>> res;
        res.push_back(nums);
        while(nextPermutation(nums))
        {
            res.push_back(nums);
        }
        return res;
    }
};