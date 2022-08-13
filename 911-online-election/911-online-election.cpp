
class TopVotedCandidate {
public:
    map<int,int> m;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=times.size(),lead=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[persons[i]]++;
            if(freq[persons[i]]>=freq[lead])
                lead=persons[i];
            m[times[i]]=lead;
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