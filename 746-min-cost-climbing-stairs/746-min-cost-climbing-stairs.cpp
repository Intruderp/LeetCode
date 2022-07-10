class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n=cost.size(),minCost=0,prev=0,prev2=cost[0];
        for(int i=2;i<=n;i++)
        {
            minCost=min(prev2+cost[i-1],prev+cost[i-2]);
            prev=prev2;
            prev2=minCost;
        }
        int res=minCost;
        prev=0;
        prev2=0;
        for(int i=2;i<=n;i++)
        {
            minCost=min(prev2+cost[i-1],prev+cost[i-2]);
            prev=prev2;
            prev2=minCost;
        }
        return min(res,minCost);
    }
};