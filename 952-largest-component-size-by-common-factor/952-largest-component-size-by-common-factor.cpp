class Solution {
public:
    unordered_map<int,vector<int>> m;
    vector<int> factors[100001];
    int vis[100001],cc=0;
    void dfs(int src)
    {
        cc++;
        vis[src]=1;
        for(int &factor:factors[src])
        {
           while(m.count(factor) and m[factor].size())
           {
               int b=m[factor].back();
               m[factor].pop_back();
               if(vis[b]==0)
                   dfs(b);
           }
        }
    }
    int largestComponentSize(vector<int>& nums)
    {
        int largestComponent=0;
        for(int &i:nums)
        {
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    if(j!=1)
                        m[j].push_back(i);
                    m[i/j].push_back(i);
                    if(j!=1)
                        factors[i].push_back(j);
                    if(i/j!=j)
                        factors[i].push_back(i/j);
                }
            }
        }
        for(int &i:nums)
        {
            if(vis[i]==0)
            {
                cc=0;
                dfs(i);
                largestComponent=max(largestComponent,cc);
            }
        }
        return largestComponent;
    }
};