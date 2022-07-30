class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> maxFreq(26,0),freq(26);
        bool poss;
        for(auto &word:words2)
        {
            fill(freq.begin(),freq.end(),0);
            for(char &c:word)
            {
                freq[c-'a']++;
                maxFreq[c-'a']=max(maxFreq[c-'a'],freq[c-'a']);
            }
        }
        for(auto &word:words1)
        {
            fill(freq.begin(),freq.end(),0);
            poss=true;
            for(char &c:word)
            {
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(freq[i]<maxFreq[i])
                {
                    poss=false;
                    break;
                }
            }
            if(poss)
                res.push_back(word);
        }
        return res;
    }
};