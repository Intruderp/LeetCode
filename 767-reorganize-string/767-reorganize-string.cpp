class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0},n=s.length(),mx=0,ind=0;
        char m;
        for(char &c:s)
        {
            freq[c-'a']++;
            if(freq[c-'a']>mx)
            {
                mx=freq[c-'a'];
                m=c;
            }
        }
        if(mx>(n+1)/2)
            return "";
        string res=s;
        while(freq[m-'a'])
        {
            res[ind]=m;
            ind+=2;
            freq[m-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            while(freq[i]--)
            {
                if(ind>=n)
                    ind=1;
                res[ind]=(i+'a');
                ind+=2;
            }
        }
        return res;
    }
};