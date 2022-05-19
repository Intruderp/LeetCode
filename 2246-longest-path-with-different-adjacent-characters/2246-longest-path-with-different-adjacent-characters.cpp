class Solution {
public:
    vector<int> adj[100000];
    int ans=0;
    int dfs(int node,int par,string &s)
    {
        int mx=0,mx2=0,x;
        for(auto &child:adj[node])
        {
            if(child!=par)
            {
                x=dfs(child,node,s);
                if(s[child]!=s[node])
                {
                    if(x>=mx)
                    {
                        mx2=mx;
                        mx=x;
                    }
                    else if(x>mx2)
                        mx2=x;
                }
            }
        }
        ans=max(ans,mx+mx2+1);
        return mx+1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0,-1,s);
        return ans;
    }
};