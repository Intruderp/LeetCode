class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n=arr.size(),x=0;
        vector<int> pre(n),res;
        for(int i=0;i<n;i++)
        {
            x^=arr[i];
            pre[i]=x;
        }
        for(auto &query:queries)
        {
            res.push_back(pre[query[0]]^pre[query[1]]^arr[query[0]]);
        }
        return res;
    }
};