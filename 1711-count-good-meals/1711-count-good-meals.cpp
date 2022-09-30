class Solution {
public:
    int countPairs(vector<int>& del) 
    {
        unordered_map<int,int> freq;
        long res=0;
        int mod=1e9+7;
        for(auto &val:del)
        {
            for(int power=1;power<=(1<<21);power*=2)
            {
                if(val>power)
                    continue;
                int req=power-val;
                if(freq.count(req))
                    res+=freq[req];
            }
            freq[val]++;
        }
        return res%mod;
    }
};