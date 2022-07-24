class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> rowFreq;
        int n=grid.size(),res=0;
        for(int i=0;i<n;i++)
            rowFreq[grid[i]]++;
        vector<int> col(n);
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
                col[i]=grid[i][j];
            res+=rowFreq[col];
        }
        return res;
    }
};