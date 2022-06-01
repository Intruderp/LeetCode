class Solution {
public:
    unordered_set<string> x;
    int ans=0;
    void help(int i,string &s,string z)
    {
        if(i==s.length())
        {
            if(x.count(z)==0)
                ans=max(ans,(int)x.size()+1);
            return ;
        }
        if(z.length()==0)
        {
            z.push_back(s[i]);
            help(i+1,s,z);
        }
        else
        {
            if(x.count(z)==0)
            {
                x.insert(z);
                help(i,s,"");
                x.erase(z);
                z.push_back(s[i]);
                help(i+1,s,z);
            }
            else
            {
                z.push_back(s[i]);
                help(i+1,s,z);
            }
        }
    }
    int maxUniqueSplit(string s) {
        help(0,s,"");
        return ans;
    }
};