class DSU
{
    private:
        vector<int> par,rank;
    public:
    DSU(int n)
    {
        par.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
    }
    int parent(int node)
    {
        if(par[node]==node)
            return node;
        return par[node]=parent(par[node]);
    }
    void uni(int a,int b)
    {
        a=parent(a);
        b=parent(b);
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
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int cc=0,n=isConnected.size();
        DSU obj(n);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(isConnected[i-1][j-1] and obj.parent(i)!=obj.parent(j))
                {
                    cc++;
                    obj.uni(i,j);
                }
            }
        }
        return n-cc;
    }
};