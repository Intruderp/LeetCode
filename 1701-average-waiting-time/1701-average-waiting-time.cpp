class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long waitingTime=0,curTime=0;
        for(auto &c:customers)
        {
            if(c[0]>=curTime)
            {
                curTime=c[0]+c[1];
                waitingTime+=c[1];
            }
            else
            {
                curTime+=c[1];
                waitingTime+=curTime-c[0];
            }
        }
        return (double)waitingTime/customers.size();
    }
};