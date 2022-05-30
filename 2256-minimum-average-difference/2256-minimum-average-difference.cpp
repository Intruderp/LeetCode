class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum=0,leftSum=0,rightSum,minAvg=1e12,avg;
        int ans=0,n=nums.size();
        for(int &num:nums)
            sum+=num;
        for(int i=0;i<n;i++)
        {
            leftSum+=nums[i];
            rightSum=sum-leftSum;
            if(i!=n-1)
                avg=abs(leftSum/(i+1)-rightSum/(n-i-1));
            else
                avg=leftSum/n;
            if(avg<minAvg)
            {
                minAvg=avg;
                ans=i;
            }
        }
        return ans;
    }
};