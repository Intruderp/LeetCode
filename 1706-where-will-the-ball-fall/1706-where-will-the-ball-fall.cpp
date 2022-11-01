class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid)
    {
        vector<int> res;
        int m=grid.size(),n=grid[0].size();
        for(int j=0;j<n;j++)
        {
            int x=0,y=j,o=1;
            while(x<m)
            {
                if(grid[x][y]==1)
                {
                    if(o==1)
                    {
                        o=2;
                        y++;
                        if(y>=n)
                            break;
                    }
                    else if(o==2)
                    {
                        o=1;
                        x++;
                    }
                    else
                        break;
                }
                else
                {
                    if(o==1)
                    {
                        o=3;
                        y--;
                        if(y<0)
                            break;
                    }
                    else if(o==3)
                    {
                        o=1;
                        x++;
                    }
                    else
                        break;
                }
            }
            if(x==m)
                res.push_back(y);
            else
                res.push_back(-1);
        }
        return res;
    }
};