class Solution {
public:
    bool check(vector<int> cnt,vector<int> req)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt[i]!=req[i] and cnt[i]>0)
            {
                for(int j=i+1;j<26;j++)
                {
                    if(cnt[j]==req[i] and cnt[j]>0)
                    {
                        swap(cnt[i],cnt[j]);
                        break;
                    }
                }
            }
            if(cnt[i]!=req[i])
                return false;
        }
        return true;
    }
    bool closeStrings(string word1, string word2) 
    {
        vector<int> cnt1(26,0),cnt2(26,0);
        for(char &c:word1)
            cnt1[c-'a']++;
        for(char &c:word2)
            cnt2[c-'a']++;
        return check(cnt1,cnt2) | check(cnt2,cnt1);
    }
};