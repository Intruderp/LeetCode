class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        map<int,int> m;
        int res=INT_MIN,j=1,n=points.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.count(i) and m.count(points[i][0]+points[i][1]))
            {
                m[points[i][0]+points[i][1]]--;
                if(m[points[i][0]+points[i][1]]==0)
                    m.erase(points[i][0]+points[i][1]);
            }
            if(j<=i)
                j=i+1;
            while(j<n and points[j][0]-points[i][0]<=k)
            {
                m[points[j][0]+points[j][1]]++;
                s.insert(j);
                j++;
            }
            if(m.size())
                res=max(res,points[i][1]-points[i][0]+m.rbegin()->first);
        }
        return res;
    }
};