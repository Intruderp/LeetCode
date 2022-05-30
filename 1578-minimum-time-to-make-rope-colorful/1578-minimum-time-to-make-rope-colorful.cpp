class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int n=colors.length(),cost=0,mx,j,sum;
        for(int i=0;i<n;i++)
        {
            j=i+1;
            mx=neededTime[i],sum=neededTime[i];
            while(j<n and colors[j]==colors[i])
            {
                sum+=neededTime[j];
                mx=max(mx,neededTime[j]);
                j++;
            }
            i=j-1;
            cost+=sum-mx;
        }
        return cost;
    }
};