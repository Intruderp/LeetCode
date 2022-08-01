class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        deque<int> q;
        int res=INT_MIN,j=1,n=points.size();
        for(int i=0;i<n;i++)
        {
            if(j<=i)
                j=i+1;
            while(j<n and points[j][0]-points[i][0]<=k)
            {
                while(!q.empty() and points[q.back()][0]+points[q.back()][1]<=points[j][0]+points[j][1])
                    q.pop_back();
                q.push_back(j);
                j++;
            }
            while(q.size() and q.front()<=i)
                q.pop_front();
            if(q.size())
                res=max(res,points[i][1]-points[i][0]+points[q.front()][0]+points[q.front()][1]);
        }
        return res;
    }
};