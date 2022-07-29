class Solution {
public:
    void fun(stack<char> &s,string &part)
    {
        if(s.size()<part.length())
            return ;
        int i=part.length()-1;
        string temp;
        while(i>=0)
        {
            if(s.top()!=part[i])
            {
                reverse(temp.begin(),temp.end());
                for(char &c:temp)
                    s.push(c);
                return ;
            }
            temp.push_back(part[i]);
            s.pop();
            i--;
        }
    }
    string removeOccurrences(string str, string part) {
        stack<char> s;
        for(char &c:str)
        {
            s.push(c);
            fun(s,part);
        }
        str.clear();
        while(!s.empty())
        {
            str.push_back(s.top());
            s.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};