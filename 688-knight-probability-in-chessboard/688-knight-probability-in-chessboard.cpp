class Solution {
public:
    int dr[8]={-2,-2,-1,-1,1,1,2,2};
    int dc[8]={1,-1,-2,2,2,-2,1,-1};
    int ni,nj;
    double dp[25][25][101];
    double help(int i,int j,int n,int k)
    {
        if(i<0 or j<0 or i>=n or j>=n)
            return 0;
        if(k==0)
            return 1;
        if(dp[i][j][k]!=2)
            return dp[i][j][k];
        double prob=0;
        for(int d=0;d<8;d++)
        {
            ni=i+dr[d],nj=j+dc[d];
            prob+=help(ni,nj,n,k-1)/8;
        }
        return dp[i][j][k]=prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int m=0;m<=k;m++)
                    dp[i][j][m]=2;
            }
        }
        return help(row,column,n,k);
    }
};