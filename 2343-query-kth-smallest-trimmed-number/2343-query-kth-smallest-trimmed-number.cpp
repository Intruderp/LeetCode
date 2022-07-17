class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        int n=nums.size(),m=queries.size(),k=nums[0].size(),j=0;
        vector<int> res(m);
        vector<pair<string,int>> v(n);
        for(auto &q:queries)
        {
            for(int i=0;i<n;i++)
                v[i]={nums[i].substr(k-q[1]),i};
            sort(v.begin(),v.end());
            res[j]=v[q[0]-1].second;
            j++;
        }
        return res;
    }
};