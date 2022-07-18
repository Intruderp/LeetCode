class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size(),m=matrix[0].size(),res=0,sum=0;
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
                matrix[i][j]+=matrix[i-1][j];
        }
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            for(int k=i;k<n;k++)
            {
                sum=0;
                freq[0]=1;
                for(int j=0;j<m;j++)
                {
                    sum+=matrix[k][j]-(i>0 ? matrix[i-1][j]:0);
                    if(freq.count(sum-target))
                        res+=freq[sum-target];
                    freq[sum]++;
                }
                freq.clear();
            }
        }
        return res;
    }
};