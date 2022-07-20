class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> v[26];
        int n=s.length();
        for(int i=0;i<n;i++)
            v[s[i]-'a'].push_back(i);
        int cnt=0,x;
        bool poss;
        for(auto &word:words)
        {
            poss=true;
            x=-1;
            for(char &c:word)
            {
                auto it=upper_bound(v[c-'a'].begin(),v[c-'a'].end(),x);
                if(it==v[c-'a'].end())
                {
                    poss=false;
                    break;
                }
                x=*it;
            }
            cnt+=poss;
        }
        return cnt;
    }
};