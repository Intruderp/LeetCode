class DSU
{
private:
    vector<int> par,rank;    
public:
    DSU(int n)
    {
        par.resize(n+1,-1);
        rank.resize(n+1,0);
    }
    int findPar(int a)
    {
        if(par[a]==-1)
            return a;
        return par[a]=findPar(par[a]);
    }
    void uni(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a==b)
            return ;
        if(rank[a]>rank[b])
            par[b]=a;
        else if(rank[a]<rank[b])
            par[a]=b;
        else
        {
            rank[a]++;
            par[b]=a;
        }
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<int> v(n+1,-1);
        for(int t=threshold+1;t<=n;t++)
        {
            for(int i=t;i<=n;i+=t)
            {
                if(v[t]==-1)
                    v[t]=i;
                else if(v[t]!=i)
                    dsu.uni(v[t],i);
            }
        }
        vector<bool> res;
        for(auto &query:queries)
        {
            if(dsu.findPar(query[0])==dsu.findPar(query[1]))
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};