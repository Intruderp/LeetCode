class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> q;
        int res=0,currentTime=1;
        sort(courses.begin(),courses.end(),comp);
        for(auto &course:courses)
        {
            if(currentTime+course[0]-1<=course[1])
            {
                res++;
                currentTime+=course[0];
                q.push(course[0]);
            }
            else if(q.size() and q.top()>course[0])
            {
                currentTime+=course[0]-q.top();
                q.pop();
                q.push(course[0]);
            } 
        }
        return res;
    }
};