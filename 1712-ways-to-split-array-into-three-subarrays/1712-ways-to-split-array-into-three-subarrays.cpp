class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int res=0,mod=1e9+7;
        int n=nums.size(),i=0,j=1,l=0,m=nums[1]+nums[0],low,high,mid,poss;
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1]+nums[i];
        while(j<n-1 and i<n-2)
        {
            l+=nums[i];
            m-=nums[i];
            if(j<=i)
            {
                j=i+1;
                m=nums[j];
            }
            while(j<n-1 and m<l)
            {
                j++;
                m+=nums[j];
            }
            low=j,high=n-2,poss=j-1;
            while(low<=high)
            {
                mid=(high+low)/2;
                if((pre[mid]-pre[i])<=(pre[n-1]-pre[mid]))
                {
                    poss=mid;
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            res=(res+poss-j+1)%mod;
            i++;
            
        }
        return res;
    }
};