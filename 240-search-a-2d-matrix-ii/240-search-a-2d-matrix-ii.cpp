class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low,mid,high;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]<=target and matrix[i][m-1]>=target)
            {
                low=0;
                high=m-1;
                while(low<=high)
                {
                    mid=(high+low)/2;
                    if(matrix[i][mid]==target)
                        return true;
                    if(matrix[i][mid]>target)
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }
        }
        return false;
    }
};