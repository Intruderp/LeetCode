
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto &word:words)
            freq[word]++;
        priority_queue<pair<int,string>> q;
        for(auto &it:freq)
        {
            if(q.size()<k)
                q.push({-it.second,it.first});
            else
            {
                if(q.top().first*(-1)<it.second)
                {
                    q.pop();
                    q.push({-it.second,it.first});
                }
                else if(q.top().first*(-1)==it.second and it.first<q.top().second)
                {
                    q.pop();
                    q.push({-it.second,it.first});
                }
            }
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