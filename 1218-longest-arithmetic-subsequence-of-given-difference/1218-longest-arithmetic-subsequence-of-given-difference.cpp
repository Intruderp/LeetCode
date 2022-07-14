class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res=0;
        unordered_map<int,int> dp;
        for(auto &num:arr)
        {
            if(dp.count(num-difference))
                dp[num]=dp[num-difference]+1;
            else
                dp[num]=1;
            res=max(res,dp[num]);
        }
        return res;
    }
};