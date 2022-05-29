class Solution {
public:
    int dp[100][21][101];
    int help(int i,int p,int t,int n,int target,vector<int>& houses, vector<vector<int>>& cost)
    {
        // if(t>target)
        //     return 5000000;
        if(i==houses.size())
            return t!=target ? 5000000:0;
        if( dp[i][p][t]!=-1)
            return  dp[i][p][t];
        int ans=5000000;
        if(houses[i]==0)
        {
            int c=0;
            for(int j=1;j<=n;j++)
            {
                c=0;
                if(j!=p)
                    c=1;
                ans=min(ans,help(i+1,j,t+c,n,target,houses,cost)+cost[i][j-1]);
            }
            return dp[i][p][t]=ans;
        }
        else
        {
            if(houses[i]==p)
                return  dp[i][p][t]=help(i+1,p,t,n,target,houses,cost);
            else
                return  dp[i][p][t]=help(i+1,houses[i],t+1,n,target,houses,cost);
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=help(0,0,0,n,target,houses,cost);
        return ans>1000000 ? -1 :ans;
    }
};