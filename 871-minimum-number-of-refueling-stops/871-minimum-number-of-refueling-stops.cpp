class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res=0,i=0,n=stations.size(),posn=0;
        sort(stations.begin(),stations.end());
        priority_queue<int> pq;
        while(true)
        {
            posn+=startFuel;
            if(posn>=target)
                return res;
            startFuel=0;
            while(i<n and posn>=stations[i][0])
            {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                break;
            startFuel+=pq.top();
            pq.pop();
            res++;
        }
        return -1;
    }
};