class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) 
    {
        int n=chargeTimes.size(),i=0,j=0,res=0;
        long cur=0,mx,sum;
        vector<long> pre(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pre[i]+=pre[i-1]+runningCosts[i-1];
        }
        deque<int> q;
        while(j<n)
        {
            while(!q.empty() and chargeTimes[q.back()]<=chargeTimes[j])
                q.pop_back();
            q.push_back(j);
            sum=pre[j+1]-pre[i];
            mx=chargeTimes[q.front()];
            cur=mx+(j-i+1)*sum;
            while(cur>budget)
            {
                while(!q.empty() and i>=q.front())
                    q.pop_front();
                i++;
                if(i>j)
                    break;
                sum=pre[j+1]-pre[i];
                mx=chargeTimes[q.front()];
                cur=mx+(j-i+1)*sum;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};