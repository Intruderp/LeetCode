class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string,int> m;
        for(auto &s:words)
            m[s]++;
        int ans=0,c=1;
        string s,x;
        for(auto &it:m)
        {
            s=it.first;
            if(s[0]==s[1])
            {
                if(it.second%2)
                {
                    if(c)
                    ans+=2;
                    c=0;
                }
                ans+=(it.second/2)*4;
            }
            else
            {
                x=s;
                reverse(x.begin(),x.end());
                if(m.count(x))
                {
                    ans+=min(it.second,m[x])*4;
                    m[x]=0;
                }
            }
        }
        return ans;
    }
};