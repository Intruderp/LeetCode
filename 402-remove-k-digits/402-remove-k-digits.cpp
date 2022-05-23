class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        string ans;
        for(char &c:num)
        {
            while(ans.length()>0 and k and ans.back()>c)
            {
                ans.pop_back();
                k--;
            }
            if(ans.length() or c!='0')
                ans.push_back(c);
        }
        while(k>0 and ans.length())
        {
            k--;
            ans.pop_back();
        }
        if(ans.length()==0)
            ans="0";
        return ans;
    }
};