class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n=nums.size(),sum=(n+1)*n/2;
        for(int &num:nums)
            sum-=num;
        return sum;
    }
};