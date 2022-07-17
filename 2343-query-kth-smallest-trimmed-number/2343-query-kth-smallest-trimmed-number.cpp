class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int n=nums.size(),k=nums[0].size();
        vector<int> res;
        vector<pair<string,int>> v;
        for(auto &q:queries)
        {
            for(int i=0;i<n;i++)
                v.push_back({nums[i].substr(k-q[1]),i});
            sort(v.begin(),v.end());
            res.push_back(v[q[0]-1].second);
            v.clear();
        }
        return res;
    }
};