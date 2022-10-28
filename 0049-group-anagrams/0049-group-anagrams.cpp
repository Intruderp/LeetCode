class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) 
    {
        vector<vector<string>> ans;
        vector<string> a;
        int n=s.size();
        vector<pair<string,string>> v;
        for(int i=0;i<n;i++)
        {
            string x=s[i],y=s[i];
            sort(y.begin(),y.end());
            v.push_back({y,x});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            string x,y;
            x=v[i].first;
            if(a.size()==0)
            a.push_back(v[i].second);
            else 
            {
                y=a.back();
                sort(y.begin(),y.end());
                if(x==y)
                a.push_back(v[i].second);
                else
                {
                    ans.push_back(a);
                    a.clear();
                    a.push_back(v[i].second);
                }
            }
        }
        if(a.size()>0)
            ans.push_back(a);
        return ans;
    }
};