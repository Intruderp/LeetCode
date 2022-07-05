class Solution {
public:
    vector<vector<int>> adj;
    vector<int> subtreeSize;
    int dfs(int src)
    {
        int curSize=1;
        for(auto &child:adj[src])
            curSize+=dfs(child);
        return subtreeSize[src]=curSize;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size(),res=0,rem;
        long long maxScore=0,curScore;
        adj.resize(n);
        subtreeSize.resize(n,0);
        for(int i=1;i<n;i++)
        {
            adj[parents[i]].push_back(i);
        }
        dfs(0);
        for(int i=0;i<n;i++)
        {
            curScore=1;
            rem=n;
            for(auto &child:adj[i])
            {
                rem-=subtreeSize[child];
                curScore*=subtreeSize[child];
            }
            curScore*=max(rem-1,1);
            if(maxScore<curScore)
            {
                maxScore=curScore;
                res=1;
            }
            else if(curScore==maxScore)
                res++;
        }
        return res;
    }
};