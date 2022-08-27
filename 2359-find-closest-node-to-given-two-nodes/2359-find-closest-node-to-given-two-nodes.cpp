class Solution {
public:
    vector<int> bfs(int src,int &n,vector<int> &adj)
    {
        vector<int> dist(n,INT_MAX);
        int d=0;
        while(src!=-1 and dist[src]==INT_MAX)
        {
            dist[src]=d++;
            src=adj[src];
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        int n=edges.size();
        vector<int> adj(n);
        for(int i=0;i<n;i++)
            adj[i]=edges[i];
        vector<int> dist1=bfs(node1,n,adj),dist2=bfs(node2,n,adj);
        int closestNode=-1,maxi=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(max(dist1[i],dist2[i])<maxi)
            {
                maxi=max(dist1[i],dist2[i]);
                closestNode=i;
            }
        }
        return closestNode;
    }
};