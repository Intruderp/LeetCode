class Solution {
public:
    int n,m,pacific[200][200],atlantic[200][200];
    void dfs(int i,int j,int prev,int ocean[][200],vector<vector<int>> &h)
    {
        if(i<0 or j<0 or i>=n or j>=m or ocean[i][j] or h[i][j]<prev)
            return ;
        ocean[i][j]=1;
        dfs(i+1,j,h[i][j],ocean,h);
        dfs(i-1,j,h[i][j],ocean,h);
        dfs(i,j+1,h[i][j],ocean,h);
        dfs(i,j-1,h[i][j],ocean,h);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) 
    {
        n=h.size(),m=h[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            dfs(0,i,0,pacific,h);
            dfs(n-1,i,0,atlantic,h);
        }
        for(int i=0;i<n;i++)
        {
            dfs(i,0,0,pacific,h);
            dfs(i,m-1,0,atlantic,h);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] and atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};