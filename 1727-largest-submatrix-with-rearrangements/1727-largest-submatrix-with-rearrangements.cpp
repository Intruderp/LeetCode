class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),res=0;
        vector<int> zeroes[m];
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[i][j]==0)
                    zeroes[j].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            for(int j=0;j<m;j++)
            {
                auto it=lower_bound(zeroes[j].begin(),zeroes[j].end(),i);
                if(it==zeroes[j].end())
                    v.push_back(n-i);
                else
                    v.push_back(*it-i);
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