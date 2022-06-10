class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int ans=0,j=0,n=s.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
            while(m[s[i]]>1)
            {
                m[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};