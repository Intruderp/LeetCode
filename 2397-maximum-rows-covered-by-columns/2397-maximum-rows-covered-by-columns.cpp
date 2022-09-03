class Solution {
public:
    void help(int j,int cols,int &n,int &m,int &res,int mask,vector<vector<int>> &mat)
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
                    if(mat[i][j] and (mask&(1<<j))==0)
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
        help(j+1,cols-1,n,m,res,mask|(1<<j),mat);
        help(j+1,cols,n,m,res,mask,mat);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) 
    {
        int res=0,n=mat.size(),m=mat[0].size();
        help(0,cols,n,m,res,0,mat);
        return res;
    }
};