class Solution {
public:
    bool isValid(string &res,string &pattern,int n)
    {
        for(int i=1;i<n;i++)
        {
            if(pattern[i-1]=='I' and res[i-1]>res[i])
                return false;
            else if(pattern[i-1]=='D' and res[i-1]<res[i])
                return false;
        }
        return true;
    }
    string smallestNumber(string pattern) 
    {
        int n=pattern.length()+1;
        string res;
        for(int i=1;i<=n;i++)
            res.push_back(i+'0');
        do
        {
            if(isValid(res,pattern,n))
                return res;
        }while(next_permutation(res.begin(),res.end()));
        return res;
    }
};