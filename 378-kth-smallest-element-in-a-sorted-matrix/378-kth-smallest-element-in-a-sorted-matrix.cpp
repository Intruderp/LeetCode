class Solution {
public:
    int n,m;
    int count(vector<vector<int>> &matrix,int x)
    {
        int cnt=0,j=m-1;
        for(int i=0;i<n;i++)
        {
            while(j>=0 and matrix[i][j]>x)
                j--;
            cnt+=j+1;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        n=matrix.size(),m=matrix[0].size();
        int res=-1,low=matrix[0][0],high=matrix[n-1][m-1],mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(count(matrix,mid)>=k)
            {
                res=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return res;
    }
};