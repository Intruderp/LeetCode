class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res+=max(0,min(row[i],col[j])-grid[i][j]);
            }
        }
        return res;
    }
};