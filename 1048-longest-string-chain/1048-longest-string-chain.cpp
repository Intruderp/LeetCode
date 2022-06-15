class Solution {
public:
    static bool comp(string x,string y)
    {
        return x.length()<y.length();
    }
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
    int longestStrChain(vector<string>& words)
    {
        unordered_map<int,vector<string>> m;
        unordered_map<string,int> dp;
        for(auto &s:words)
        {
            m[s.length()].push_back(s);
            dp[s]=1;
        }
        sort(words.rbegin(),words.rend(),comp);
        int ans=0,len;
        for(auto &s:words)
        {
            len=s.length();
            if(m.count(len+1))
            {
                for(string &x:m[len+1])
                {
                    if(isPredecessor(s,x))
                        dp[s]=max(dp[s],dp[x]+1);
                }
            }
            ans=max(ans,dp[s]);
        }
        return ans;
    }
};