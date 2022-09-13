class DSU
{
    vector<int> par,rank;
public:
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
    }
    int findPar(int node)
    {
        if(par[node]==node)
            return node;
        return par[node]=findPar(par[node]);
    }
    void uni(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
        if(a==b)
            return ;
        if(rank[a]<rank[b])
            par[a]=b;
        else if(rank[a]>rank[b])
            par[b]=a;
        else
        {
            rank[a]++;
            par[b]=a;
        }
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int>&b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        int q=queries.size(),i=0;
        vector<bool> res(q);
        for(int i=0;i<q;i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        sort(edgeList.begin(),edgeList.end(),comp);
        DSU dsu(n);
        for(auto &query:queries)
        {
            while(i<edgeList.size() and query[2]>edgeList[i][2])
            {
                dsu.uni(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            res[query[3]]=(dsu.findPar(query[0])==dsu.findPar(query[1]));
        }
        return res;
    }
};