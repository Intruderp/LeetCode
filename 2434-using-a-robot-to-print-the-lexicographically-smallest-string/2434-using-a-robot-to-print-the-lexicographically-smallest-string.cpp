class Solution {
public:
    string robotWithString(string s) 
    {
        string t,p;
        vector<int> freq(26,0);
        for(auto &c:s)
            freq[c-'a']++;
        int n=s.length(),i=0;
        while(i<n)
        {
            if(t.length()==0)
            {
                t.push_back(s[i]);
                freq[s[i]-'a']--;
                i++;
            }
            else
            {
                char c=t.back();
                bool found=false;
                for(char x='a';x<c;x++)
                {
                    if(freq[x-'a'])
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                {
                    p.push_back(t.back());
                    t.pop_back();
                }
                else
                {
                    freq[s[i]-'a']--;
                    t.push_back(s[i]);
                    i++;
                }
            }
        }
        while(t.length()>0)
        {
            p.push_back(t.back());
            t.pop_back();
        }
        return p;
    }
};