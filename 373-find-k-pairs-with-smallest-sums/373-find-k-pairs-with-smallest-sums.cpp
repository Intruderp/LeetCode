class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k)
    {
        vector<vector<int>> res;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        int n=v1.size(),m=v2.size();
        for(int i=0;i<min(n,k);i++)
            q.push({v1[i]+v2[0],i,0});
        while(k-- and !q.empty())
        {
            auto t=q.top();
            q.pop();
            res.push_back({v1[t[1]],v2[t[2]]});
            if(t[2]+1<m)
                q.push({v1[t[1]]+v2[t[2]+1],t[1],t[2]+1});
        }
        return res;
    }
};