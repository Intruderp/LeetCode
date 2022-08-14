class Solution {
public:
    int edgeScore(vector<int>& edges) 
    {
        int n=edges.size(),res=0;
        long maxi=0;
        vector<long> cnt(n,0);
        for(int i=0;i<n;i++)
        {
            cnt[edges[i]]+=i;
            if(cnt[edges[i]]>maxi)
            {
                maxi=cnt[edges[i]];
                res=edges[i];
            }
            else if(maxi==cnt[edges[i]])
                res=min(res,edges[i]);
        }
        return res;
    }
};