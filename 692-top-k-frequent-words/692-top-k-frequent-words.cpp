
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto &word:words)
            freq[word]++;
        priority_queue<pair<int,string>> q;
        for(auto &it:freq)
        {
            q.push({-it.second,it.first});
            if(q.size()>k)
                q.pop();
        }
        vector<string> res;
        while(!q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};