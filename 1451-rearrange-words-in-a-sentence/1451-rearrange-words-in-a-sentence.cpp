class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> m;
        string s;
        text[0]=tolower(text[0]);
        for(char &c:text)
        {
            if(c==' ')
            {
                m[s.length()].push_back(s);
                s.clear();
                continue;
            }
            s.push_back(c);
        }
        m[s.length()].push_back(s);
        string res;
        for(auto &it:m)
        {
            for(auto &word:it.second)
            {
                res+=word;
                res+=" ";
            }
        }
        res.pop_back();
        res[0]=toupper(res[0]);
        return res;
    }
};