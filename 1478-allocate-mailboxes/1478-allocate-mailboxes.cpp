class Solution {
public:
    int dp[100][101];
    int help(int i,int k,int &n,vector<int> &pre)
    {
        if(i==n)
            return 0;
        if(k==0)
            return 1e7;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=INT_MAX;
        for(int j=i;j<n;j++)
        {
            int mid=(i+j)/2,sum=pre[j]-pre[mid];
            if((j-i+1)%2)
                sum-=((mid>0 ? pre[mid-1]:0)-(i>0 ? pre[i-1]:0));
            else
                sum-=(pre[mid]-(i>0 ? pre[i-1]:0));
            ans=min(ans,help(j+1,k-1,n,pre)+sum);
        }
        return dp[i][k]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        for(int i=1;i<n;i++)
            houses[i]+=houses[i-1];
        memset(dp,-1,sizeof(dp));
        return help(0,k,n,houses);
    }
};