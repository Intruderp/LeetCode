class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
        int ans=0,n=words.size();
        vector<string> v;
        for(string &s:words)
        {
            string bit(26,'0');
            for(char &c:s)
            {
                bit[c-'a']='1';
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
                    if(v[i][bit]=='1' and v[j][bit]=='1')
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