class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        deque<int> q{0};
        for(int i=1;i<n;i++)
        {
            if(q.front()<i-k)
                q.pop_front();
            dp[i]=dp[q.front()]+nums[i];
            while(!q.empty() and dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};