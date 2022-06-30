class Solution {
public:
    vector<int> adj[13];
    const int mod=1e9+7;
    int cnt=0,dp[5000][13];
    int help(int i,int p,int n)
    {
        if(i==n)
            return 1;
        if(dp[i][p]!=-1)
            return dp[i][p];
        int res=0;
        for(auto &child:adj[p])
            res=(res+help(i+1,child,n))%mod;
        return dp[i][p]=res;
    }
    int numOfWays(int n) {
        adj[0]={1,2,3,4,5,6,7,8,9,10,11,12};
        adj[1]={2,3,5,6,11};
        adj[2]={1,4,7,9,12};
        adj[3]={1,4,7,8};
        adj[4]={2,3,8,11};
        adj[5]={1,2,9,10};
        adj[6]={1,7,8,10,11};
        adj[7]={2,3,5,6,12};
        adj[8]={3,4,6,12};
        adj[9]={2,5,10,11};
        adj[10]={5,6,9,12};
        adj[11]={1,4,6,9,12};
        adj[12]={2,7,8,10,11};
        memset(dp,-1,sizeof(dp));
        return help(0,0,n);
    }
};