class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        int n=books.size(),cur,mx;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            cur=0,mx=0;
            for(int j=i;j>=1;j--)
            {
                cur+=books[j-1][0];
                mx=max(mx,books[j-1][1]);
                if(cur>shelfWidth)
                    break;
                dp[i]=min(dp[i],dp[j-1]+mx);
            }
        }
        return dp[n];
    }
};