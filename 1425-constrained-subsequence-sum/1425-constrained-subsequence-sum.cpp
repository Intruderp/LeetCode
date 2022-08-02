class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int> dp(n+1,INT_MIN);
        dp[0]=0;
        deque<int> q;
        q.push_front(0);
        for(int i=1;i<=n;i++)
        {
            if(!q.empty() and i-q.front()>k)
                q.pop_front();
            dp[i]=nums[i-1];
            dp[i]+=max(0,dp[q.front()]);
            while(!q.empty() and dp[q.back()]<=dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return *max_element(dp.begin()+1,dp.end());
    }
};