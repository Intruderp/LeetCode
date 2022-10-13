class Solution {
public:
    vector<int> generateSubsetSum(vector<int> &v)
    {
        vector<int> res;
        int n=v.size(),mask=(1<<n);
        for(int i=0;i<mask;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if((1<<j)&i)
                    sum+=v[j];
            }
            res.push_back(sum);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) 
    {
        int n=nums.size();
        if(n==1)
            return min(abs(goal-nums[0]),abs(goal));
        vector<int> v1,v2;
        for(int i=0;i<n/2;i++)
            v1.push_back(nums[i]);
        for(int i=n/2;i<n;i++)
            v2.push_back(nums[i]);
        vector<int> subsetSum1=generateSubsetSum(v1),subsetSum2=generateSubsetSum(v2);
        sort(subsetSum2.begin(),subsetSum2.end());
        int res=INT_MAX;
        for(auto sum:subsetSum1)
        {
            auto it=lower_bound(subsetSum2.begin(),subsetSum2.end(),goal-sum);
            if(it!=subsetSum2.end())
                res=min(res,abs(goal-(sum+*it)));
            if(it!=subsetSum2.begin())
            {
                it--;
                res=min(res,abs(goal-(sum+*it)));
            }
        }
        return res;
    }
};