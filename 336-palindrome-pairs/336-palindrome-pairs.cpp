class Solution {
public:
    bool isPalin(string &x,string &y)
    {
        string temp=x+y;
        int i=0,j=temp.length()-1;
        while(i<=j)
        {
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool check(string &temp)
    {
        int i=0,j=temp.length()-1;
        while(i<=j)
        {
            if(temp[i]!=temp[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        unordered_map<string,vector<int>> m;
        unordered_set<string> st;
        set<pair<int,int>> a;
        vector<int> empty;
        vector<vector<int>> ans;
        for(int i=0;i<words.size();i++)
        {
            m[words[i]].push_back(i);
            if(words[i].length()==0)
                empty.push_back(i);
            reverse(words[i].begin(),words[i].end());
            st.insert(words[i]);
        }
        for(auto &it:m)
        {
            string s=it.first;
            if(s.length()>0 and check(s))
            {
                for(int i:empty)
                {
                    for(int j:it.second)
                    {
                        ans.push_back({i,j});
                        ans.push_back({j,i});
                    }
                }
            }
            string x;
            vector<int> v;
            for(int i=0;i<s.length();i++)
            {
                x.push_back(s[i]);
                if(st.count(x))
                {
                    string z=x;
                    reverse(z.begin(),z.end());
                    if(isPalin(s,z))
                    {
                        for(int i:m[z])
                            v.push_back(i);
                    }
                }
            }
            for(int i:it.second)
            {
                for(int j:v)
                {
                    if(i!=j)
                        a.insert({i,j});
                }
            }
            v.clear();
            x.clear();
            for(int i=s.length()-1;i>=0;i--)
            {
                x.push_back(s[i]);
                if(m.count(x))
                {
                    if(isPalin(x,s))
                    {
                        for(int i:m[x])
                            v.push_back(i);
                    }
                }
            }
            for(int i:it.second)
            {
                for(int j:v)
                {
                    if(i!=j)
                        a.insert({j,i});
                }
            }
        }
        for(auto &it:a)
            ans.push_back({it.first,it.second});
        return ans;
    }
};