class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        double res=0;
        int n=classes.size(),i;
        priority_queue<pair<double,int>> q;
        for(i=0;i<n;i++)
        {
            q.push({(double)(classes[i][0]+1)/(classes[i][1]+1)-(double)classes[i][0]/classes[i][1],i});
        }
        while(extraStudents--)
        {
            i=q.top().second;
            q.pop();
            classes[i][0]++;
            classes[i][1]++;
            q.push({(double)(classes[i][0]+1)/(classes[i][1]+1)-(double)classes[i][0]/classes[i][1],i});
        }
        for(int i=0;i<n;i++)
        {
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};