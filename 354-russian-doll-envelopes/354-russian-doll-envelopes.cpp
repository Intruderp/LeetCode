class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[0]==b[0] ? a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        vector<int> lis;
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        for(int i=0;i<n;i++)
        {
            if(lis.size()==0)
                lis.push_back(envelopes[i][1]);
            else
            {
                auto it=lower_bound(lis.begin(),lis.end(),envelopes[i][1]);
                if(it==lis.end())
                    lis.push_back(envelopes[i][1]);
                else
                    *it=envelopes[i][1];
            }
        }
        return lis.size();
    }
};