class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,int>> pq;
        int res=INT_MIN,j=1,n=points.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            if(j<=i)
                j=i+1;
            while(j<n and points[j][0]-points[i][0]<=k)
            {
                pq.push({points[j][0]+points[j][1],j});
                j++;
            }
            while(pq.size() and pq.top().second<=i)
                pq.pop();
            if(pq.size())
                res=max(res,points[i][1]-points[i][0]+pq.top().first);
        }
        return res;
    }
};