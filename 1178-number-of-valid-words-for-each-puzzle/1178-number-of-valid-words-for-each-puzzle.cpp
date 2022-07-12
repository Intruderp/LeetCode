class Solution {
public:
    const int mod=1e9+7;
    int hash(string &s)
    {
        long long res=0,p=31,power=1;
        for(char &c:s)
        {
            res=(res+(c-'a'+1)*power)%mod;
            power=(power*p)%mod;
        }
        return res;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
    {
        unordered_map<int,int> m;
        int n,cnt;
        vector<int> res;
        for(string &word:words)
        {
            string temp;
            sort(word.begin(),word.end());
            temp.push_back(word[0]);
            n=word.length();
            for(int i=1;i<n;i++)
            {
                if(word[i]!=temp.back())
                    temp.push_back(word[i]);
            }
            m[hash(temp)]++;
        }
        for(string &word:puzzles)
        {
            string temp;
            sort(word.begin()+1,word.end());
            n=word.length();
            temp.push_back(word[0]);
            for(int i=1;i<n;i++)
            {
                if(word[i]!=temp.back() and word[0]!=temp[i])
                    temp.push_back(word[i]);
            }
            cnt=0;
            n=temp.length();
            string p;
            for(int mask=1;mask<(1<<n);mask++)
            {
                string x;
                x.push_back(temp[0]);
                for(int i=1;i<n;i++)
                {
                    if((mask&(1<<i)))
                        x.push_back(temp[i]);
                }
                sort(x.begin(),x.end());
                if(p==x)
                    continue;
                p=x;
                if(m.count(hash(x)))
                {
                    cnt+=m[hash(x)];
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};