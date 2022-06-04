class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> m;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            m[intervals[i][0]]=i;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            auto it=m.lower_bound(intervals[i][1]);
            if(it!=m.end())
                ans[i]=it->second;
            else
                ans[i]=-1;
        }
        return ans;
    }
};