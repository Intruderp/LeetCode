class Solution {
public:
    int minDeletions(string s) {
        int res=0,n=s.length(),extra;
        vector<int> freq(26,0),cnt(n+1,0);
        for(char &c:s)
            freq[c-'a']++;
        for(int &i:freq)
            cnt[i]++;
        for(int i=n;i>0;i--)
        {
            extra=max(0,cnt[i]-1);
            res+=extra;
            cnt[i-1]+=extra;
        }
        return res;
        
    }
};