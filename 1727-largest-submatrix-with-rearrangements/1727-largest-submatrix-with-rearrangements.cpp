class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),res=0,next=n;
        for(int j=0;j<m;j++)
        {
            next=n;
            for(int i=n-1;i>=0;i--)
            {
                if(matrix[i][j]==0)
                    next=i;
                matrix[i][j]=next;
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<m;j++)
            {
                v.push_back(matrix[i][j]-i);
            }
            sort(v.rbegin(),v.rend());
            for(int j=0;j<v.size();j++)
            {
                res=max(res,(j+1)*v[j]);
            }
        }
        return res;
    }
};