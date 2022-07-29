class Solution {
public:
    bool check(string &x,string &y)
    {
        int n=x.length();
        vector<int> match(26,-1),freq(26,0);
        for(int i=0;i<n;i++)
        {
            if(match[x[i]-'a']!=-1 and match[x[i]-'a']!=y[i]-'a')
                return false;
            if(match[x[i]-'a']==-1)
            {
                if(freq[y[i]-'a'])
                    return false;
                freq[y[i]-'a']=1;
            }
            match[x[i]-'a']=y[i]-'a';
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto &word:words)
        {
            if(check(word,pattern))
                res.push_back(word);
        }
        return res;
    }
};