unordered_map<string,int> freq;
bool comp(string &x,string &y)
{
    if(freq[x]==freq[y])
        return x<y;
    return freq[x]>freq[y];
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        freq.clear();
        for(auto &word:words)
            freq[word]++;
        sort(words.begin(),words.end(),comp);
        vector<string> res;
        for(auto &word:words)
        {
            if(res.size() and res.back()==word)
                continue;
            res.push_back(word);
            if(res.size()==k)
                break;
        }
        return res;
    }
};