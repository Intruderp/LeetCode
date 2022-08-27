class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int n=matrix.size(),m=matrix[0].size(),sum=0,res=INT_MIN,req;
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
                matrix[i][j]+=matrix[i-1][j];
        }
        set<int> pre;
        for(int r=0;r<n;r++)
        {
            for(int r2=r;r2<n;r2++)
            {
                sum=0;
                pre.insert(0);
                for(int j=0;j<m;j++)
                {
                    sum+=matrix[r2][j]-(r>0 ? matrix[r-1][j]:0);
                    req=sum-k;
                    auto it=pre.lower_bound(req);
                    if(it!=pre.end())
                        res=max(res,sum-*it);
                    pre.insert(sum);
                }
                pre.clear();
            }
        }
        return res;
    }
};