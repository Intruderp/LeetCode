class Solution {
public:
    void help(int j,int cols,int &n,int &m,int &res,vector<int> &taken,vector<vector<int>> &mat)
    {
        if(cols<0)
            return ;
        if(j==m)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                bool poss=true;
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j] and !taken[j])
                    {
                        poss=false;
                        break;
                    }
                }
                cnt+=poss;
            }
            res=max(res,cnt);
            return ;
        }
        taken[j]=1;
        help(j+1,cols-1,n,m,res,taken,mat);
        taken[j]=0;
        help(j+1,cols,n,m,res,taken,mat);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int res=0,n=mat.size(),m=mat[0].size();
        vector<int> taken(m,0);
        help(0,cols,n,m,res,taken,mat);
        return res;
    }
};