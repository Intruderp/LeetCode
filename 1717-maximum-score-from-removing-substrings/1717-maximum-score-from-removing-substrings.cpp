class Solution {
public:
    int help(string &str,int x,char t1,char t2)
    {
        int res=0;
        stack<char> s;
        for(char &c:str)
        {
            if(s.empty())
                s.push(c);
            else if(s.top()==t1 and c==t2)
            {
                res+=x;
                s.pop();
            }
            else
                s.push(c);
        }
        str.clear();
        while(s.size())
        {
            str.push_back(s.top());
            s.pop();
        }
        reverse(str.begin(),str.end());
        return res;
    }
    int maximumGain(string s, int x, int y) {
        int score=0;
        if(x>y)
            score=help(s,x,'a','b')+help(s,y,'b','a');
        else
            score=help(s,y,'b','a')+help(s,x,'a','b');
        return score;
    }
};