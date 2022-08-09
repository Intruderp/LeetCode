class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day=0;
        map<int,long> prev;
        for(auto &task:tasks)
        {
            day++;
            if(prev.count(task))
            {
                if(day-prev[task]<=space)
                    day+=space-(day-prev[task])+1;
            }
            prev[task]=day;
        }
        return day;
    }
};