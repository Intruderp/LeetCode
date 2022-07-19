class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        ans.push_back({1});
        for(int i=2;i<=n;i++)
        {
            v.clear();
            for(int j=0;j<i;j++)
            {
                if(j==0 or j==i-1)
                    v.push_back(1);
                else 
                {
                    v.push_back(ans[i-2][j-1]+ans[i-2][j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};