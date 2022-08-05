class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k)
    {
        int n=nums.size(),i=0,res=n+1;
        long sum=0;
        deque<pair<long,int>> q;
        while(i<n)
        {
            sum+=nums[i];
            while(!q.empty() and q.back().first>=sum)
                q.pop_back();
            q.push_back({sum,i});
            while(sum-q.front().first>=k)
            {
                res=min(res,i-q.front().second);
                q.pop_front();
            }
            if(sum>=k)
                res=min(res,i+1);
            i++;
        }
        return res==n+1 ?-1:res;
    }
};