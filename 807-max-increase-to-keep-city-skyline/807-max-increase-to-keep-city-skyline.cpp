class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0,mx=0,mx2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mx=0,mx2=0;
                for(int k=0;k<n;k++)
                    mx=max(mx,grid[k][j]);
                for(int k=0;k<m;k++)
                    mx2=max(mx2,grid[i][k]);
                res+=max(0,min(mx,mx2)-grid[i][j]);
            }
        }
        return res;
    }
};