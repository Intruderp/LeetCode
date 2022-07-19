class Solution {
public:
    int n,dp[1000];
    int help(int i,int shelfWidth,vector<vector<int>> &books)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX,cur=0,mx=0;
        for(int j=i;j<n;j++)
        {
            cur+=books[j][0];
            mx=max(mx,books[j][1]);
            if(cur>shelfWidth)
                break;
            ans=min(ans,help(j+1,shelfWidth,books)+mx);
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        n=books.size();
        memset(dp,-1,sizeof(dp));
        return help(0,shelfWidth,books);
    }
};