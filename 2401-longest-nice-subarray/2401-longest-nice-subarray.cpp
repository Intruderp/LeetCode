class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            vector<int> bit(32,0);
            bool poss=true;
            for(int j=i;j<n;j++)
            {
               for(int b=0;b<32;b++)
               {
                   if((1<<b)&nums[j])
                       bit[b]++;
                   if(bit[b]>1)
                   {
                       poss=false;
                       break;
                   }
               }
               if(poss)
                   res=max(res,j-i+1);
                else
                    break;
            }
        }
        return res;
    }
};