class DSU
{
    vector<int> par,rank;
public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=1;i<=n;i++)
            par[i]=i;
    }
    void uni(int a,int b)
    {
        a=findPar(a);
        b=findPar(b);
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
    int findPar(int node)
    {
        if(par[node]==node)
            return node;
        return par[node]=findPar(par[node]);
    }
};
class Solution {
public:
    bool gcdSort(vector<int>& nums) 
    {
        int n=*max_element(nums.begin(),nums.end());
        DSU ds(n);
        vector<int> p(n+1,0);
        for(auto &num:nums)
            p[num]=1;
        for(int num=2;num<=n/2;num++)
        {
            for(int i=2*num;i<=n;i+=num)
            {
                if(p[i])
                    ds.uni(num,i);
            }
        }
        p=nums;
        sort(nums.begin(),nums.end());
        n=p.size();
        for(int i=0;i<n;i++)
        {
            if(p[i]!=nums[i] and ds.findPar(p[i])!=ds.findPar(nums[i]))
                return false;
        }
        return true;
    }
};