class Solution {
public:
    int beautySum(string s) {
        int res=0,mx,mn,n=s.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++)
        {
            fill(freq.begin(),freq.end(),0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                mx=0,mn=n;
                for(int c=0;c<26;c++)
                {
                    if(freq[c])
                    {
                        mx=max(mx,freq[c]);
                        mn=min(mn,freq[c]);
                    }
                }
                res+=mx-mn;
            }
        }
        return res;
    }
};