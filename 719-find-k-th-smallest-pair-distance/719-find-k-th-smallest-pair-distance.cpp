class Solution {
public:
    bool poss(vector<int> &nums,int &n,int &k,int &x)
    {
        int i=0,j=0,cnt=0;
        while(j<n)
        {
            while(nums[j]-nums[i]>x)
                i++;
            cnt+=j-i;
            if(cnt>=k)
                return true;
            j++;
        }
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),low=0,high=nums[n-1]-nums[0],mid,res;
        while(high>=low)
        {
            mid=(high+low)/2;
            if(poss(nums,n,k,mid))
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};