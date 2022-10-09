class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        int n=pref.size(),i=0;
        vector<int> res{pref[0]};
        for(int i=1;i<n;i++)
        {
            res.push_back(pref[i]^pref[i-1]);
        }
        return res;
    }
};