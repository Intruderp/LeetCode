class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int len=s.length(),ind=-1,ind2=-1;
        for(int i=0;i<len-1;i++)
        {
            if(s[i]<s[i+1])
                ind=i;
        }
        if(ind==-1)
            return -1;
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]>s[ind])
            {
                ind2=i;
                break;
            }
        }
        swap(s[ind],s[ind2]);
        reverse(s.begin()+ind+1,s.end());
        long long x=stoll(s);
        if(x>INT_MAX)
            return -1;
        return x;
    }
};