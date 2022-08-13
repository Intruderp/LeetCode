class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        int n=s.length(),i=0,j=0,len=words[0].length(),m=words.size(),cnt=words.size();
        unordered_map<string,int> w;
        for(string &s:words)
            w[s]++;
        for(int i=0;i<=n-len*m;i++)
        {
            unordered_map<string,int> cur;
            cnt=words.size();
            for(int j=i;j<i+len*m;j+=len)
            {
                string x=s.substr(j,len);
                if(w.count(x)==0)
                    break;
                else
                {
                    if(cur[x]==w[x])
                        break;
                    cnt--;
                    cur[x]++;
                }
            }
            if(cnt==0)
                res.push_back(i);
        }
        return res;
    }
};