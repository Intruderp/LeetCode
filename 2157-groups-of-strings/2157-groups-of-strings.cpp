class DSU
{
    private:
    unordered_map<int,int> par,rank;
    public:
    int parent(int &s)
    {
        if(par.count(s)==0)
            return s;
        return par[s]=parent(par[s]);
    }
    void Union(int a,int b)
    {
        a=parent(a);
        b=parent(b);
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
            par[b]=a;
            rank[a]++;
        }
    }
};
class Solution {
public:
    vector<int> groupStrings(vector<string>& words) 
    {
        int n,x;
        DSU ds;
        vector<int> w;
        for(string &s:words)
        {
            x=0;
            for(char &c:s)
                x|=(1<<(c-'a'));
            w.push_back(x);
        }
        unordered_set<int> st{w.begin(),w.end()};
        for(int s:w)
        {
            for(int i=0;i<26;i++)
            {
                x=s;
                if((s&(1<<i)))
                    x&=(~(1<<i));
                else
                    x|=(1<<i);
                if(st.count(x))
                    ds.Union(s,x);
            }
            for(int i=0;i<26;i++)
            {
                if((s&(1<<i))==0)
                    continue;
                for(int j=0;j<26;j++)
                {
                    if(s&(1<<j))
                        continue;
                    x=s;
                    x|=(1<<j);
                    x&=(~(1<<i));
                    if(st.count(x))
                        ds.Union(s,x);
                }
            }
        }
        vector<int> ans(2,0);
        unordered_map<int,int> freq;
        for(int &s:w)
        {
            ans[1]=max(ans[1],++freq[ds.parent(s)]);
        }
        ans[0]=freq.size();
        return ans;
    }
};