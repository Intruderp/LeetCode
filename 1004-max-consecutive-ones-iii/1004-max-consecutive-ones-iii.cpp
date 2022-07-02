class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),res=0;
        while(i<n)
        {
            while(j<n and (k or nums[j]))
            {
                if(nums[j]==0)
                    k--;
                j++;
            }
            res=max(res,j-i);
            if(nums[i]==0)
                k++;
            i++;
        }
        return res;
    }
};