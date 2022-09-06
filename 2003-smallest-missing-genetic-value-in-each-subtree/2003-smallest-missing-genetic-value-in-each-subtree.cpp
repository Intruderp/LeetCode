class Solution {
public:
    void dfs(int src,vector<int> &nums,vector<int> &present,vector<int> adj[])
    {
        present[nums[src]]=1;
        for(auto &child:adj[src])
        {
            if(present[nums[child]]==0)
                dfs(child,nums,present,adj);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) 
    {
        int n=parents.size(),node=-1;
        vector<int> adj[n],res(n,1),present(100002,0);
        int missing=1;
        for(int i=1;i<n;i++)
        {
            adj[parents[i]].push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                node=i;
                break;
            }
        }
        while(node!=-1)
        {
            dfs(node,nums,present,adj);
            while(present[missing])
            {
                missing++;
            }
            res[node]=missing;
            node=parents[node];
        }
        return res;
    }
};