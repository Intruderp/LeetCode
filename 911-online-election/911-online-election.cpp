class comp{
public:
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        if(a.first==b.first)
            return true;
        return a.first<b.first;
    }
};
class TopVotedCandidate {
public:
    map<int,int> m;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        int n=times.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[persons[i]]++;
            pq.push({freq[persons[i]],persons[i]});
            m[times[i]]=pq.top().second;    
        }
    }
    int q(int t) {
        auto it=m.upper_bound(t);
        return (--it)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */