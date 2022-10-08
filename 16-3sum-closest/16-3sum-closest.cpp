class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) 
    {
        int ans,d=INT_MAX,x,y,z,n=nums.size(),j,k,a;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            x=nums[i];
            j=0,k=n-1;
            while(j<i and k>i)
            {
                y=nums[j];
                z=nums[k];
                a=x+y+z;
                if(d>abs(t-a))
                {
                    d=abs(t-a);
                    ans=a;
                }
                if(t>a)
                    j++;
                else 
                    k--;
            }
        }
        return ans;
    }
};