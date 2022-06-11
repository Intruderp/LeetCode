class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int vis[1001]={0},n=nums.size();
        vis[start]=1;
        int steps=0;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int sz=q.size();
            steps++;
            while(sz--)
            {
                int f=q.front();
                q.pop();
                for(int i=0;i<n;i++)
                {
                    if(f+nums[i]==goal)
                        return steps;
                    if(f-nums[i]==goal)
                        return steps;
                    if((f^nums[i])==goal)
                        return steps;
                    if(f+nums[i]>=0 and f+nums[i]<=1000 and vis[f+nums[i]]==0)
                    {
                        vis[f+nums[i]]=1;
                        q.push(f+nums[i]);
                    }
                    if(f-nums[i]>=0 and f-nums[i]<=1000 and vis[f-nums[i]]==0)
                    {
                        vis[f-nums[i]]=1;
                        q.push(f-nums[i]);
                    }
                    if((f^nums[i])>=0 and (f^nums[i])<=1000 and vis[f^nums[i]]==0)
                    {
                        vis[f^nums[i]]=1;
                        q.push(f^nums[i]);
                    }
                }
            }
        }
        return -1;
    }
};