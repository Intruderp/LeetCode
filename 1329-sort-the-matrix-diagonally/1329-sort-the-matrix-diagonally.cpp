class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),x,y;
        for(int j=0;j<m;j++)
        {
            x=0,y=j;
            vector<int> temp;
            while(x<n and y<m)
            {
                temp.push_back(mat[x++][y++]);
            }
            sort(temp.rbegin(),temp.rend());
            x=0,y=j;
            while(x<n and y<m)
            {
                mat[x++][y++]=temp.back();
                temp.pop_back();
            }
        }
        for(int i=1;i<n;i++)
        {
            x=i,y=0;
            vector<int> temp;
            while(x<n and y<m)
            {
                temp.push_back(mat[x++][y++]);
            }
            sort(temp.rbegin(),temp.rend());
            x=i,y=0;
            while(x<n and y<m)
            {
                mat[x++][y++]=temp.back();
                temp.pop_back();
            }
        }
        return mat;
    }
};