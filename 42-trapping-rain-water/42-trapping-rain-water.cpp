class Solution {
public:
    int trap(vector<int>& h)
    {
        int n=h.size(),mx=0,j;
        vector<pair<int,int>> v(n);
        for(int i=n-1;i>=0;i--)
        {
            if(h[i]>=mx)
            {
                mx=h[i];
                j=i;
            }
            v[i]={mx,j};
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            int sum=0,len,he;
            mx=v[i+1].first;
            if(mx<h[i])
            {
                j=v[i+1].second;
                int sum=0,len,he;
                for(int k=i+1;k<j;k++)
                   sum+=h[k];
                len=j-i-1;
                he=min(h[i],h[j]);
                ans+=len*he-sum;
                i=j-1;
            }
            else
            {
                mx=0;
                sum=0;
                for(int k=i+1;k<n;k++)
                {
                    if(h[k]>=h[i])
                    {
                        j=k;
                        break;
                    }
                    sum+=h[k];
                }
                len=j-i-1;
                he=min(h[i],h[j]);
                ans+=len*he-sum;
                i=j-1;
                    
            }
        }
        return ans;
    }
};