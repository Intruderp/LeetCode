class Solution {
public:
    int help(string &s,int &k,int &unique)
    {
        int n=s.length(),i=0,j=0,cur=0,cnt=0,maxL=0;
        vector<int> freq(26,0);
        while(j<n)
        {
            if(freq[s[j]-'a']==0)
                cur++;
            freq[s[j]-'a']++;
            if(freq[s[j]-'a']==k)
                cnt++;
            while(cur>unique)
            {
                if(freq[s[i]-'a']==k)
                    cnt--;
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0)
                    cur--;
                i++;
            }
            if(cur==cnt)
                maxL=max(maxL,j-i+1);
            j++;
        }
        return maxL;
    }
    int longestSubstring(string s, int k) 
    {
        int maxLen=0;
        for(int u=1;u<=26;u++)
        {
            maxLen=max(maxLen,help(s,k,u));
        }
        return maxLen;
    }
};