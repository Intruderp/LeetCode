class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        int n=palindrome.length(),i=0;
        if(n==1)
            return "";
        while(i<n/2)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
            i++;
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};