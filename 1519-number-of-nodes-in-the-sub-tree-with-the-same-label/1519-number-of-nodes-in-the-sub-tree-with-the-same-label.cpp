class Solution {
public:
    vector<int> ans,adj[100000];
    vector<int> dfs(int src,int par,string &s)
    {
        vector<int> cnt(26,0),v;
        cnt[s[src]-'a']=1;
        for(auto &it:adj[src])
        {
            if(it!=par)
            {
                v=dfs(it,src,s);
                for(int i=0;i<v.size();i++)
                    cnt[i]+=v[i];
            }
        }
        ans[src]=cnt[s[src]-'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        ans.resize(n);
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,labels);
        return ans;
    }
};