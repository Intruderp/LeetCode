class Solution {
public:
    const int mod=1e9+7;
    int dp[50][50][51];
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 and j>=0 and i<m and j<n;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dr[]={0,1,-1,0};
        int dc[]={1,0,0,-1};
        int ni,nj;
        for(int moves=1;moves<=maxMove;moves++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int d=0;d<4;d++)
                    {
                        ni=i+dr[d];
                        nj=j+dc[d];
                        if(isValid(ni,nj,m,n))
                            dp[i][j][moves]+=dp[ni][nj][moves-1];
                        else
                            dp[i][j][moves]++;
                        dp[i][j][moves]%=mod;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};