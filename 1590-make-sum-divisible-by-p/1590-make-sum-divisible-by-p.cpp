class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        int need=0,n=nums.size();
        for(int &i:nums)
        {
            need=(need+i)%p;
        }
        if(need==0)
            return 0;
        int req,cur=0,ans=n,i=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int &num:nums)
        {
            cur=(cur+num)%p;
            if(m.count((cur-need+p)%p))
                ans=min(ans,i-m[(cur-need+p)%p]);
            m[cur]=i;
            i++;
        }
        return ans==n ? -1 :ans;
    }
};