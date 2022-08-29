class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &g)
    {
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or g[i][j]=='0')
            return ;
        g[i][j]='0';
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
    int numIslands(vector<vector<char>>& g) 
    {
        int cc=0;
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                if(g[i][j]=='1')
                {
                    cc++;
                    dfs(i,j,g);
                }
            }
        }
        return cc;
    }
};