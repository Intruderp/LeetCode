class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);
        set<int> s;
        int req=0;
        for(auto &interval:intervals)
        {
            req=2;
            auto it=s.lower_bound(interval[0]);
            if(it!=s.end() and *it<=interval[1])
            {
                req--;
                it++;
                if(it!=s.end() and *it<=interval[1])
                req--;
            }
            if(req==1)
            {
                if(s.count(interval[1]))
                    s.insert(interval[1]-1);
                else
                    s.insert(interval[1]);
            }
            else if(req==2)
            {
                s.insert(interval[1]-1);
                s.insert(interval[1]);
            }
        }
        return s.size();
    }
};