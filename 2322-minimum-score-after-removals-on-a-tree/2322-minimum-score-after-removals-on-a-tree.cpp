class Solution {
public:
    vector<int> vis,xor_val;
    int n;
    int pre(int i,vector<int> &values,vector<int> adj[])
    {
        int x = values[i];
        vis[i]=1;
        for (int j:adj[i])
        {
            if(vis[j]==0)
            x ^= pre(j,values,adj);
        }
        xor_val[i] = x;
        return x;
    }
    vector<int> v;
    void dfs(int src,vector<int> adj[])
    {
        v.push_back(src);
        vis[src]=1;
        for(auto &child:adj[src])
        {
            if(vis[child]==0)
                dfs(child,adj);
        }
    }
    int help(vector<int> &c1,vector<int> &c2,vector<int> adj[],vector<int> &nums)
    {
        int val=0,val2,val3,res=INT_MAX,t=0;
        for(auto &node:c1)
            val^=nums[node];
         for(auto &node:c2)
            t^=nums[node];
        vector<int> v(n,0);
        for(auto &node:c2)
        {
            v[node]=1;
            for(auto &child:adj[node])
            {
                if(v[child])
                    continue;
                val2=xor_val[child];
                val3=t^val2;
                res=min(res,max({val,val2,val3})-min({val,val2,val3}));
            }
        }
        swap(t,val);
        for(auto &node:c1)
        {
            v[node]=1;
            for(auto &child:adj[node])
            {
                if(v[child])
                    continue;
                val2=xor_val[child];
                val3=t^val2;
                res=min(res,max({val,val2,val3})-min({val,val2,val3}));
            }
        }
        return res;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n=nums.size();
        int res=INT_MAX;
        vis.resize(n);
        xor_val.resize(n);
        vector<int> adj[n],c,c2;
        for(int j=0;j<n-1;j++)
        {
            for(int i=0;i<n;i++)
            {
                vis[i]=0;
                adj[i].clear();
            }
            c.clear();
            for(int k=0;k<n-1;k++)
            {
                if(j==k)
                    continue;
                adj[edges[k][0]].push_back(edges[k][1]);
                adj[edges[k][1]].push_back(edges[k][0]);
            }
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    dfs(i,adj);
                    if(c.size()==0)
                        c=v;
                    else
                        c2=v;
                    v.clear();
                }
            }
            for(int i=0;i<n;i++)
                vis[i]=0;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                   pre(i,nums,adj);
                }
            }
            res=min(res,help(c,c2,adj,nums));
        }
        return res;
    }
};