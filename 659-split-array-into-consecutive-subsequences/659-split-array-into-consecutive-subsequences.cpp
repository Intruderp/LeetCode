class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int,int> freq,req;
        for(auto &num:nums)
            freq[num]++;
        for(auto &num:nums)
        {
            if(freq[num]==0)
                continue;
            if(req[num])
            {
                req[num]--;
                freq[num]--;
                req[num+1]++;
            }
            else if(freq[num] and freq[num+1] and freq[num+2])
            {
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                req[num+3]++;
            }
            else
                return false;
        }
        return true;
    }
};