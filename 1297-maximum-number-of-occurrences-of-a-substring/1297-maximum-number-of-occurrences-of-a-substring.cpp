class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> freq;
        string cur;
        unordered_set<char> letters;
        int res=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<min(n,i+maxSize);j++)
            {
                cur.push_back(s[j]);
                letters.insert(s[j]);
                if(cur.length()>=minSize and letters.size()<=maxLetters)
                {
                    freq[cur]++;
                    res=max(res,freq[cur]);
                }
            }
            cur.clear();
            letters.clear();
        }
        return res;
    }
};