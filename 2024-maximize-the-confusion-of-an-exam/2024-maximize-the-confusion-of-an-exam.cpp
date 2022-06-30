class Solution {
public:
    int help(string &s,int k,char c)
    {
        int n=s.length(),i=0,j=0,res=0;
        while(j<n)
        {
            while(j<n and k)
            {
                if(s[j]==c)
                    k--;
               j++;
            }
            while(j<n and s[j]!=c)
                j++;
            res=max(res,j-i);
            if(s[i]==c)
                k++;
            i++;
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
       return max(help(answerKey,k,'T'),help(answerKey,k,'F'));
    }
};