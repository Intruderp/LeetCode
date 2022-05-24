class Solution {
public:
    int longestValidParentheses(string str) 
    {
        stack<pair<char,int>> s;
        for(int i=0;i<str.length();i++)
        {
            if(s.empty())
                s.push({str[i],i});
            else 
            {
                if(s.top().first=='(' and str[i]==')')
                    s.pop();
                else 
                    s.push({str[i],i});
            }
        }
        int f=str.size(),ans=0,n=str.size();
        f--;
        n--;
        while(!s.empty())
        {
            int x=s.top().second;
            s.pop();
            ans=max(ans,f-x);
            f=x-1;
        }
        ans=max(ans,f+1);
        return ans;
    }
};