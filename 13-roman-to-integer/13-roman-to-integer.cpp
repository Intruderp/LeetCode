class Solution {
public:
    int romanToInt(string s) 
    {
        int num=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='I')
            {
                if(s[i+1]=='V')
                {
                    i++;
                    num+=4;
                }
                else if(s[i+1]=='X')
                {
                    i++;
                    num+=9;
                }
                else
                    num++;
            }
            else if(s[i]=='V')
                num+=5;
            else if(s[i]=='X')
            {
                if(s[i+1]=='L')
                {
                    i++;
                    num+=40;
                }
                else if(s[i+1]=='C')
                {
                    i++;
                    num+=90;
                }
                else
                    num+=10;
            }
            else if(s[i]=='L')
                num+=50;
            else if(s[i]=='C')
            {
                if(s[i+1]=='D')
                {
                    i++;
                    num+=400;
                }
                else if(s[i+1]=='M')
                {
                    i++;
                    num+=900;
                }
                else
                    num+=100;
            }
            else if(s[i]=='D')
                num+=500;
            else
                num+=1000;
        }
        return num;
    }
};