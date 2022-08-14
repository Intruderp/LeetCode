class Solution {
public:
    string maxValue(string n, int x) 
    {
        int len=n.length();
        if(n[0]=='-')
        {
            for(int i=1;i<len;i++)
            {
                if(n[i]-'0'>x)
                {
                    n.insert(i,to_string(x));
                    return n;
                }
            }
            n.push_back('0'+x);
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(n[i]-'0'<x)
                {
                    n.insert(i,to_string(x));
                    return n;
                }
            }
            n.push_back('0'+x);
        }
        return n;
    }
};