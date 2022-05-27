class DSU
{
    private:
    vector<int> par,rank;
    public:
    DSU(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,0);
        iota(par.begin(),par.end(),0);
    }
    int find(int a)
    {
        if(a==par[a])
            return a;
        return par[a]=find(par[a]);
    }
    void Union(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a==b)
            return ;
        if(rank[a]>rank[b])
        {
            par[b]=a;
        }
        else if(rank[a]<rank[b])
        {
            par[a]=b;
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
    int largestComponentSize(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end()),ans=0;
        DSU ds(m);
        unordered_map<int,int> freq;
        for(int &i:nums)
        {
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    ds.Union(i,j);
                    ds.Union(i,i/j);
                }
            }
        }
        for(int &i:nums)
        {
            ans=max(ans,++freq[ds.find(i)]);
        }
        return ans;
    }
};