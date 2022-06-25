class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum=0,n=s.length(),x;
        for(int i=n-1;i>=0;i--)
        {
            sum=(sum+shifts[i])%26;
            x=(s[i]-'a'+97+sum);
            if(x<=122)
                s[i]=x;
            else
            {
                x-=123;
                s[i]=x+97;
            }
            
        }
        return s;
    }
};