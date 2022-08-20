class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n=s.length();
        vector<int> cnt(n,0);
        for(auto &shift:shifts)
        {
            if(shift[2])
            {
                cnt[shift[0]]++;
                if(shift[1]+1<n)
                    cnt[shift[1]+1]--;
            }
            else
            {
                cnt[shift[0]]--;
                if(shift[1]+1<n)
                    cnt[shift[1]+1]++;
            }
        }
        for(int i=1;i<n;i++)
            cnt[i]+=cnt[i-1];
        for(int i=0;i<n;i++)
        {
            if(cnt[i]>=0)
            {
                cnt[i]%=26;
                if('z'-s[i]<cnt[i])
                    s[i]='a'+cnt[i]-('z'-s[i])-1;
                else
                    s[i]+=cnt[i];
            }
            else
            {
                cnt[i]=abs(cnt[i])%26;
                if(s[i]-'a'<cnt[i])
                    s[i]='z'-(cnt[i]-(s[i]-'a'+1));
                else
                    s[i]-=(cnt[i]);
            }
        }
        return s;
    }
};