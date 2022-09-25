class DSU
{
    vector<int> par,rank;
public:
    DSU(int n)
    {
        for(int i=0;i<n;i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
            return node;
        return par[node]=findPar(par[node]);
    }
    void Union(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a==b)
            return ;
        if(rank[a]<rank[b])
        {
            par[a]=b;
        }
        else if(rank[a]>rank[b])
        {
            par[b]=a;
        }
        else
        {
            rank[a]++;
            par[b]=a;
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
    {
        int n=vals.size(),res=0;
        vector<pair<int,int>> adj[n];
        vector<int> v[100001];
        for(int i=0;i<n;i++)
        {
            v[vals[i]].push_back(i);
        }
        for(auto &edge:edges)
        {
            adj[edge[0]].push_back({vals[edge[1]],edge[1]});
            adj[edge[1]].push_back({vals[edge[0]],edge[0]});
        }
        for(int i=0;i<n;i++)
            sort(adj[i].rbegin(),adj[i].rend());
        DSU dsu(n);
        for(int i=0;i<=100000;i++)
        {
            for(auto &node:v[i])
            {
                while(adj[node].size()>0 and adj[node].back().first<=i)
                {
                    dsu.Union(node,adj[node].back().second);
                    adj[node].pop_back();
                }
            }
            unordered_map<int,int> freq;
            for(auto &node:v[i])
            {
                freq[dsu.findPar(node)]++;
            }
            for(auto &f:freq)
                res+=f.second*(f.second+1)/2;
        }
        return res;
    }
};