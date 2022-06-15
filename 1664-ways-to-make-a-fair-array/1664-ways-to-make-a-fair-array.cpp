class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size(),evenSum=0,oddSum=0,res=0,leftEvenSum=0,leftOddSum=0,rightOddSum=0,rightEvenSum=0;
        for(int i=0;i<n;i++)
        {
            if(i%2)
                oddSum+=nums[i];
            else
                evenSum+=nums[i];
        }
        rightOddSum=oddSum;
        rightEvenSum=evenSum;
        for(int i=0;i<n;i++)
        {
            if(i%2)
                rightOddSum-=nums[i];
            else 
                rightEvenSum-=nums[i];
            
            if(leftEvenSum+rightOddSum==leftOddSum+rightEvenSum)
                res++;
            
            if(i%2)
                leftOddSum+=nums[i];
            else 
                leftEvenSum+=nums[i];
        }
        return res;
    }
};