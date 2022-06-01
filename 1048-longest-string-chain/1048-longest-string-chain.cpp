class Solution {
public:
    static bool comp(string x,string y)
    {
        return x.length()<y.length();
    }
    unordered_map<int,vector<string>> m;
    unordered_map<string,int> dp;
    bool isPredecessor(string &x,string &y)
    {
        int i=0,j=0,cnt=0;
        while(i<x.length() and j<y.length())
        {
            if(x[i]==y[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
                cnt++;
            }
            if(cnt>1)
                return false;
        }
        return true;
    }
    int help(string &s)
    {
        if(dp.count(s))
            return dp[s];
        int len=s.length();
        if(m.count(len+1)==0)
            return 1;
        int ans=1;
        for(auto &y:m[len+1])
        {
            if(isPredecessor(s,y))
                ans=max(ans,help(y)+1);
        }
        return dp[s]=ans;
    }
    int longestStrChain(vector<string>& words)
    {
        for(auto &s:words)
            m[s.length()].push_back(s);
        sort(words.begin(),words.end(),comp);
        int ans=0;
        for(auto &s:words)
            ans=max(ans,help(s));
        return ans;
    }
};