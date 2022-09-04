class Solution {
public:
    int atMostS(vector<int> &nums,int sum)
    {
        if(sum<0)
            return 0;
        int res=0,i=0,j=0,cur=0,n=nums.size();
        while(j<n)
        {
            cur+=nums[j];
            while(cur>sum)
            {
                cur-=nums[i];
                i++;
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return atMostS(nums,goal)-atMostS(nums,goal-1);
    }
};