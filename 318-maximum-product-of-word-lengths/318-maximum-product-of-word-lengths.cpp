class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int ans=0,n=words.size();
        vector<int> v;
        int bit=0;
        for(string &s:words)
        {
            bit=0;
            for(char &c:s)
            {
                bit|=(1<<(c-'a'));
            }
            v.push_back(bit);
        }
        bool poss;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                poss=true;
                for(int bit=0;bit<26;bit++)
                {
                    if(((1<<bit)&v[i]) and ((1<<bit)&v[j]))
                    {
                        poss=false;
                        break;
                    }
                }
                int len=words[i].length()*words[j].length();
                if(poss)
                    ans=max(ans,len);
            }
        }
        return ans;
    }
};