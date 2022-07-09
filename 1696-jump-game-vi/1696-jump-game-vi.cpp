class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        dp[0]=nums[0];
        map<int,int> m;
        m[dp[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(i-k-1>=0)
            {
                m[dp[i-k-1]]--;
                if(m[dp[i-k-1]]==0)
                    m.erase(dp[i-k-1]);
            }
            dp[i]=(--m.end())->first+nums[i];
            m[dp[i]]++;
                
        }
        return dp[n-1];
    }
};