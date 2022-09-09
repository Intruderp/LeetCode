class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) 
    {
        int ans=0,mx=0,n=p.size(),x,y,z;
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({p[i][0],p[i][1]});
        int suff[n];
        sort(a.begin(),a.end());
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,a[i].second);
            suff[i]=mx;
        }
        for(int i=0;i<n;i++)
        {
            x=a[i].first,y=a[i].second;
            pair<int,int> pp={x+1,0};
            auto it=lower_bound(a.begin(),a.end(),pp);
            if(it!=a.end())
            {
                z=it-a.begin();
                ans+=(suff[z]>y);
            }
        }
        return ans;
    }
};