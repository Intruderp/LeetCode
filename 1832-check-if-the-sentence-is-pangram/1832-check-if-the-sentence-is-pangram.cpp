class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int> freq(26,0);
        int cnt=0;
        for(char &c:sentence)
        {
            freq[c-'a']++;
            if(freq[c-'a']==1)
                cnt++;
        }
        return cnt==26;
    }
};